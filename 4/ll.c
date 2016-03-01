#include "apue.h"
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;
    struct stat st;
    char *desc;
    if (argc != 2)
        err_quit("usage: ll directory_name");
    if ((dp = opendir(argv[1])) == NULL) {
        err_sys("can't open %s", argv[1]);
    }
    while ((dirp = readdir(dp)) != NULL) {
        if (lstat(dirp->d_name, &st) < 0) {
            err_ret("lstat error");
            continue;
        }
        if (S_ISREG(st.st_mode))
            desc = "regular";
        else if (S_ISDIR(st.st_mode))
            desc = "directory";
        printf("%10s ", desc);
        printf("%s", dirp->d_name);
        putchar('\n');
    }
    closedir(dp);
    return 0;
}
