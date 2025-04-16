#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <mqueue.h>
#include <string.h>
#include <sys/types.h>

#define TASK_QUEUE "/task_queue"
#define RESULT_QUEUE "/result_queue"

// Task structure
typedef struct {
    int effort;
} Task;

// Result structure
typedef struct {
    int worker_id;
    pid_t pid;
    int task_count;
    int total_time;
} Result;

// Function that the worker will execute when invoked
void worker_process(int id) {
    mqd_t task_q = mq_open(TASK_QUEUE, O_RDONLY);
    mqd_t result_q = mq_open(RESULT_QUEUE, O_WRONLY);

    Task task;
    int task_count = 0, total_time = 0;

    while (1) {
        if (mq_receive(task_q, (char*)&task, sizeof(Task), NULL) == -1) {
            perror("mq_receive");
            continue;
        }

        if (task.effort == 0) {
            printf("%s | Worker #%02d | Received termination task\n", __TIME__, id);
            break;
        }

        printf("%s | Worker #%02d | Received task with effort %d\n", __TIME__, id, task.effort);
        sleep(task.effort);
        task_count++;
        total_time += task.effort;
    }

    Result result = {
        .worker_id = id,
        .pid = getpid(),
        .task_count = task_count,
        .total_time = total_time
    };
    mq_send(result_q, (char*)&result, sizeof(Result), 0);

    mq_close(task_q);
    mq_close(result_q);
}
