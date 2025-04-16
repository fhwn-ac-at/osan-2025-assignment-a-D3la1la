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

#define TASK_QUEUE "/task_queue"
#define RESULT_QUEUE "/result_queue"

typedef struct {
    int effort;
} Task;

typedef struct {
    int worker_id;
    pid_t pid;
    int task_count;
    int total_time;
} Result;

void spawn_workers(int n);

int main(int argc, char *argv[])
{
    if (argc != 7) {
        fprintf(stderr, "Usage: %s -w <workers> -t <tasks> -s <queue_size>\n", argv[0]);
        exit(1);
    }

    int workers = atoi(argv[2]);
    int tasks = atoi(argv[4]);
    int queue_size = atoi(argv[6]);

    printf("%s | Ventilator | Starting %d workers for %d tasks and a queue size of %d\n", __TIME__, workers, tasks, queue_size);

    struct mq_attr attr = {0};
    attr.mq_maxmsg = queue_size;
    attr.mq_msgsize = sizeof(Task);

    mq_unlink(TASK_QUEUE);
    mq_unlink(RESULT_QUEUE);

    mqd_t task_q = mq_open(TASK_QUEUE, O_CREAT | O_WRONLY, 0644, &attr);
    mqd_t result_q = mq_open(RESULT_QUEUE, O_CREAT | O_RDONLY, 0644, NULL);

    if (task_q == -1 || result_q == -1) {
        perror("mq_open");
        exit(1);
    }

    for (int i = 0; i < workers; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            char id_str[10];
            sprintf(id_str, "%d", i + 1);
            execl("./worker", "worker", id_str, NULL);  // Now calling the worker process
            perror("execl");
            exit(1);
        } else {
            printf("%s | Worker #%02d | Started worker PID %d\n", __TIME__, i + 1, pid);
        }
    }

    srand(time(NULL));
    printf("%s | Ventilator | Distributing tasks\n", __TIME__);

    for (int i = 0; i < tasks; i++) {
        Task t = { .effort = (rand() % 10) + 1 };
        printf("%s | Ventilator | Queuing task #%d with effort %d\n", __TIME__, i+1, t.effort);
        mq_send(task_q, (char*)&t, sizeof(Task), 0);
    }

    printf("%s | Ventilator | Sending termination tasks\n", __TIME__);
    Task term = { .effort = 0 };
    for (int i = 0; i < workers; i++) {
        mq_send(task_q, (char*)&term, sizeof(Task), 0);
    }

    for (int i = 0; i < workers; i++) {
        Result r;
        mq_receive(result_q, (char*)&r, sizeof(Result), NULL);
        printf("%s | Ventilator | Worker %d processed %d tasks in %d seconds\n", __TIME__, r.worker_id, r.task_count, r.total_time);
    }

    for (int i = 0; i < workers; i++) {
        int status;
        pid_t pid = wait(&status);
        printf("%s | Ventilator | Worker with PID %d exited with status %d\n", __TIME__, pid, WEXITSTATUS(status));
    }

    mq_close(task_q);
    mq_close(result_q);
    mq_unlink(TASK_QUEUE);
    mq_unlink(RESULT_QUEUE);
    return 0;
}
