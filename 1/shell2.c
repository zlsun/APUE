#include "apue.h"
#include <sys/wait.h>

static void sig_int(int);

int main(int argc, char *argv[])
{
    char buf[MAXLINE];
    pid_t pid;
    int status;
    int len;
    if (signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("signal error");
    printf("%% ");
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        len = strlen(buf);
        if (buf[len - 1] == '\n')
            buf[len - 1] = 0;
        if ((pid = fork()) < 0) {
            err_sys("fork error");
        } else if (pid == 0) { /* child */
            execl("/bin/sh", "sh", "-c", buf, (char*)0);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        } else { /* parent */
            if ((pid = waitpid(pid, &status, 0)) < 0)
                err_sys("waitpid error");
            printf("%% ");
        }
    }
    return 0;
}

void sig_int(int signo)
{
    printf("interrupt %d\n", signo);
}
