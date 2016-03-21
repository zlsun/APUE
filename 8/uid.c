#include "apue.h"
#include <unistd.h>

int main(int argc, char *argv[])
{
#define PR_ID(id) printf("%-5s: %d\n", #id, get##id());
    PR_ID(pid)
    PR_ID(ppid)
    PR_ID(uid)
    PR_ID(euid)
    PR_ID(gid)
    PR_ID(egid)
    return 0;
}
