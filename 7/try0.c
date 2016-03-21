#include "apue.h"
#include <setjmp.h>

struct Exception {
    int code;
    jmp_buf jb;
} e;

#define TRY(e) e.code = setjmp(e.jb); if (e.code == 0)
#define CATCH(e) else
#define THROW(e, c) longjmp(e.jb, c)

int main(int argc, char *argv[])
{
    TRY(e) {
        printf("before error\n");
        THROW(e, 1);
        printf("after error (shouldn't printed)\n");
    } CATCH(e) {
        TRY(e) {
            printf("error %d\n", e.code);
            THROW(e, 2);
        }
        CATCH(e) {
            printf("error %d\n", e.code);
        }
    }
    return 0;
}
