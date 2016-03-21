#include "apue.h"
#include <setjmp.h>

#define TRY \
    { \
        jmp_buf __ex_jb; \
        int __ex_code; \
        switch(__ex_code = setjmp(__ex_jb)) { \
            case 0:
#define YRT \
        } \
    }
#define CATCH(c) break; case c:
#define CATCH_ALL break; default:
#define EXEC (__ex_code)
#define THROW(c) longjmp(__ex_jb, c)

int main(int argc, char *argv[])
{
    TRY {
        printf("before error\n");
        THROW(1);
        printf("after error (shouldn't printed)\n");
    }
    CATCH_ALL {
        TRY {
            printf("error %d\n", EXEC);
            THROW(2);
        }
        CATCH(2) {
            printf("error %d\n", EXEC);
        }
        YRT
    }
    YRT
    return 0;
}
