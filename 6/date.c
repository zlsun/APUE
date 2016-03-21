#include "apue.h"
#include <time.h>

int main(int argc, char *argv[])
{
    time_t t;
    struct tm* m;
    char buf[100];
    time(&t);
    m = localtime(&t);
    printf("%s", asctime(m));
    strftime(buf, 100, "%a %b %d %T %Z %Y", m);
    printf("%s\n", buf);
    return 0;
}
