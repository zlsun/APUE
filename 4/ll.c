#include "apue.h"
#include <dirent.h>

void permission(char* buf, mode_t m)
{
    int i, mask, shift, perm;
    for (i = 0; i < 3; ++i) {
        shift = (2 - i) * 3;
        mask = 7 << shift;
        perm = (m & mask) >> shift;
        buf[i * 3 + 0] = perm & 4 ? 'r' : '-';
        buf[i * 3 + 1] = perm & 2 ? 'w' : '-';
        buf[i * 3 + 2] = perm & 1 ? 'x' : '-';
    }
}

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;
    struct stat st;
    char buf[11] = {0};
    if (argc != 2)
        err_quit("usage: ll directory_name");
    if ((dp = opendir(argv[1])) == NULL) {
        err_sys("can't open %s", argv[1]);
    }
    if (chdir(argv[1]) < 0) {
        err_sys("can't chdir %s", argv[1]);
    }
    while ((dirp = readdir(dp)) != NULL) {
        if (lstat(dirp->d_name, &st) < 0) {
            err_ret("lstat error");
            continue;
        }
        if (S_ISREG(st.st_mode))
            buf[0] = '-';
        else if (S_ISDIR(st.st_mode))
            buf[0] = 'd';
        else if (S_ISCHR(st.st_mode))
            buf[0] = 'c';
        else if (S_ISBLK(st.st_mode))
            buf[0] = 'b';
        else if (S_ISFIFO(st.st_mode))
            buf[0] = 'f';
        else if (S_ISLNK(st.st_mode))
            buf[0] = 'l';
        else if (S_ISSOCK(st.st_mode))
            buf[0] = 's';
        else
            buf[0] = '*';
        permission(&buf[1], st.st_mode);
        printf("%s %s\n", buf, dirp->d_name);
    }
    closedir(dp);
    return 0;
}
