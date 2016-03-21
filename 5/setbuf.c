#include "apue.h"

void mysetbuf(FILE *restrict fp, char *restrict buf) {
    /* buf 为 NULL时，设为无缓冲区 */
    if (buf == NULL) setvbuf(fp, buf, _IONBF, 0);
    /* buf 非空时，设为长度为 BUFSIZ 的用户 buf，模式通常为全缓冲 */
    /* 但如果 fp 与终端设备相关，也可设为行缓冲 */
    else setvbuf(fp, buf, _IOFBF, BUFSIZ);
}

int main(int argc, char *argv[])
{
    char buf[BUFSIZ];
    mysetbuf(stdin, buf);
    mysetbuf(stdout, NULL);
    char bf[MAXLINE];
    while (fgets(bf, MAXLINE, stdin) != NULL) {
        if (fputs(bf, stdout) == EOF)
            err_sys("output error");
    }
    if (ferror(stdin)) {
        err_sys("input error");
    }
    fputs(buf, stdout);
    return 0;
}
