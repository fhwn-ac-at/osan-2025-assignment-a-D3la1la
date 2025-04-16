#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <mqueue.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

// Define queue names
#define TASK_QUEUE "/task_queue"
#define RESULT_QUEUE "/result_queue"

// Define the structure of a Task
typedef struct
{
    int effort; // Represents the effort required for a task
} Task;

// Define the structure for worker results
typedef struct
{
    int worker_id;    // Worker ID
    pid_t pid;        // Process ID of the worker
    int task_count;   // Number of tasks the worker processed
    int total_time;   // Total time taken by the worker to process tasks
} Result;

// Function to spawn worker processes
void spawn_workers(int n);

int main(int argc, char *argv[])
{
    // Check if correct number of arguments is passed
    if (argc != 7) 
    {
        fprintf(stderr, "Usage: %s -w <workers> -t <tasks> -s <queue_size>\n", argv[0]);
        exit(1);
    }

    // Parse command-line arguments
    int workers = atoi(argv[2]);    // Number of worker processes
    int tasks = atoi(argv[4]);      // Number of tasks to distribute
    int queue_size = atoi(argv[6]); // Maximum number of tasks in the queue

    // Log the start of the program
    printf("%s | Ventilator | Starting %d workers for %d tasks and a queue size of %d\n", 
           __TIME__, workers, tasks, queue_size);

    // Set up message queue attributes
    struct mq_attr attr = { 0 };
    attr.mq_maxmsg = queue_size;  // Max number of messages in the queue
    attr.mq_msgsize = sizeof(Task); // Message size for each task

    // Clean up any pre-existing message queues
    mq_unlink(TASK_QUEUE);
    mq_unlink(RESULT_QUEUE);

    // Open the message queues (task queue for writing, result queue for reading)
    mqd_t task_q = mq_open(TASK_QUEUE, O_CREAT | O_WRONLY, 0644, &attr);
    mqd_t result_q = mq_open(RESULT_QUEUE, O_CREAT | O_RDONLY, 0644, NULL);

    // Check for errors in opening the message queues
    if (task_q == -1 || result_q == -1) 
    {
        perror("mq_open");
        exit(1);
    }

    // Fork worker processes
    for (int i = 0; i < workers; i++) 
    {
        pid_t pid = fork();
        
        if (pid == 0) 
        {
            // Child process (worker)
            char id_str[10];
            sprintf(id_str, "%d", i + 1);
            execl("./worker", "worker", id_str, NULL); // Execute the worker process
            perror("execl");  // If execl fails
            exit(1);
        } 
        else 
        {
            // Parent process (Ventilator)
            printf("%s | Worker #%02d | Started worker PID %d\n", __TIME__, i + 1, pid);
        }
    }

    // Seed the random number generator and start task distribution
    srand(time(NULL));
    printf("%s | Ventilator | Distributing tasks\n", __TIME__);

    // Distribute tasks to the task queue
    for (int i = 0; i < tasks; i++) 
    {
        Task t = { .effort = (rand() % 10) + 1 }; // Random effort between 1 and 10
        printf("%s | Ventilator | Queuing task #%d with effort %d\n", __TIME__, i + 1, t.effort);
        mq_send(task_q, (char*)&t, sizeof(Task), 0); // Send task to the queue
    }

    // Send termination task to all workers
    printf("%s | Ventilator | Sending termination tasks\n", __TIME__);
    Task term = { .effort = 0 }; // Termination task (effort 0)
    for (int i = 0; i < workers; i++) 
    {
        mq_send(task_q, (char*)&term, sizeof(Task), 0); // Send termination signal to each worker
    }

    // Receive results from workers
    for (int i = 0; i < workers; i++) 
    {
        Result r;
        mq_receive(result_q, (char*)&r, sizeof(Result), NULL); // Receive worker result
        printf("%s | Ventilator | Worker %d processed %d tasks in %d seconds\n", 
               __TIME__, r.worker_id, r.task_count, r.total_time);
    }

    // Wait for worker processes to finish
    for (int i = 0; i < workers; i++) 
    {
        int status;
        pid_t pid = wait(&status); // Wait for worker to exit
        printf("%s | Ventilator | Worker with PID %d exited with status %d\n", 
               __TIME__, pid, WEXITSTATUS(status));
    }

    // Clean up message queues
    mq_close(task_q);
    mq_close(result_q);
    mq_unlink(TASK_QUEUE);
    mq_unlink(RESULT_QUEUE);
    
    return 0;
}
