#include "apue.h"
#include <sys/wait.h>

#define FORK(pid) \
    if ((pid = fork()) < 0) \
        err_sys("fork error"); \
    else if (pid == 0)

#define WAIT(pid) \
    if (pid > 0 && waitpid(pid, NULL, 0) != pid) { \
        err_sys("waitpid error"); \
    }

int main(int argc, char *argv[])
{
    int i = 0;
    pid_t pid;
    FORK(pid) {
        i++;
        FORK(pid) {
            i++;
            sleep(1);
        }
        sleep(1);
    }
    printf("[%d] pid = %d, ppid = %d\n", i, getpid(), getppid());
    WAIT(pid)
    printf("[%d] pid = %d, ppid = %d\n", i, getpid(), getppid());
    return 0;
}
