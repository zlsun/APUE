#include "apue.h"
#include <pwd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
        err_quit("usage: getpw user");
    struct passwd *pw;
    if ((pw = getpwnam(argv[1])) == NULL)
        err_quit("no user %s", argv[1]);
    printf("pw_name: %s\n", pw->pw_name);
    printf("pw_passwd: %s\n", pw->pw_passwd);
    printf("pw_uid: %d\n", pw->pw_uid);
    printf("pw_gid: %d\n", pw->pw_gid);
    printf("pw_gecos: %s\n", pw->pw_gecos);
    printf("pw_dir: %s\n", pw->pw_dir);
    printf("pw_shell: %s\n", pw->pw_shell);
    return 0;
}
