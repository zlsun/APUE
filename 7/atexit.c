#include "apue.h"

static void myexit1(void);
static void myexit2(void);

int main(int argc, char *argv[])
{
    printf("main begin\n");
    if (atexit(myexit2) != 0)
        err_sys("Can't register myexit2");
    if (atexit(myexit1) != 0)
        err_sys("Can't register myexit1");
    if (atexit(myexit1) != 0)
        err_sys("Can't register myexit1");
    printf("main end\n");
    return 0;
}

static void myexit1(void) {
    printf("myexit1\n");
}

static void myexit2(void) {
    printf("myexit2\n");
}
