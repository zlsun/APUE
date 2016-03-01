#include "apue.h"
#include <errno.h>
#include <limits.h>

void pr_sysconf(char* msg, int name)
{
    long val;
    fputs(msg, stdout);
    errno = 0;
    if ((val = sysconf(name)) < 0) {
        if (errno != 0) {
            if (errno == EINVAL)
                fputs("(not supported)\n", stdout);
            else
                err_sys("sysconf error\n");
        } else {
            fputs("no\n", stdout);
        }
    } else {
        printf("%ld\n", val);
    }
}

void pr_pathconf(char* msg, char* path, int name)
{
    long val;
    fputs(msg, stdout);
    errno = 0;
    if ((val = pathconf(path, name)) < 0) {
        if (errno != 0) {
            if (errno == EINVAL)
                fputs("(not supported)\n", stdout);
            else
                err_sys("pathconf error, path = %s\n", path);
        } else {
            fputs("no\n", stdout);
        }
    } else {
        printf("%ld\n", val);
    }
}
