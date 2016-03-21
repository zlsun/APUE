#include "apue.h"
#include <sys/resource.h>

void print_limit(char *name, int resource) {
    struct rlimit rl;
    getrlimit(resource, &rl);
    printf("%s ", name);
    if (rl.rlim_cur != RLIM_INFINITY) printf(" %-9lu", rl.rlim_cur);
    else printf(" unlimited");
    if (rl.rlim_max != RLIM_INFINITY) printf(" %-9lu", rl.rlim_max);
    else printf(" unlimited");
    printf("\n");
}

int main(int argc, char *argv[])
{
    print_limit("cputime     ", RLIMIT_CPU);
    print_limit("filesize    ", RLIMIT_FSIZE);
    print_limit("datasize    ", RLIMIT_DATA);
    print_limit("stacksize   ", RLIMIT_STACK);
    print_limit("coredumpsize", RLIMIT_CORE);
    /* print_limit("memoryuse   ", RLIMIT_); */
    print_limit("maxproc     ", RLIMIT_NPROC);
    print_limit("descriptors ", RLIMIT_NOFILE);
    print_limit("memorylocked", RLIMIT_MEMLOCK);
    /* print_limit("addressspace", RLIMIT_); */
    print_limit("maxfilelocks", RLIMIT_LOCKS);
    /* print_limit("sigpending  ", RLIMIT_); */
    /* print_limit("msgqueue    ", RLIMIT_); */
    /* print_limit("nice        ", RLIMIT_); */
    /* print_limit("rt_priority ", RLIMIT_); */
    /* print_limit("rt_time     ", RLIMIT_); */
    return 0;
}
