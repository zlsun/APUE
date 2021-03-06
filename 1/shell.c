#include "apue.h"
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    char buf[MAXLINE];
    pid_t pid;
    int status;
    int len;
    printf("%% ");
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        len = strlen(buf);
        if (buf[len - 1] == '\n')
            buf[len - 1] = 0;
        if ((pid = fork()) < 0) {
            err_sys("fork error");
        } else if (pid == 0) { /* child */
            execlp(buf, buf, (char*)0);
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
