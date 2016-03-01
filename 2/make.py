
import re

def make(sys, path):
    for l in open(sys):
        l = l[:-1]
        l = re.split(r'\t+', l)
        print('''\
    printf("{0:25}");
    #ifdef {0}
        printf("\\t%ld", (long){0}+0);
    #else
        printf("\\tno");
    #endif
    #ifdef {1}
        pr_sysconf("\\t", {1});
    #else
        printf("\\tno\\n");
    #endif
'''.format(*l))
    for l in open(path):
        l = l[:-1]
        l = re.split(r'\t+', l)
        print('''\
    printf("{0:25}");
    #ifdef {0}
        printf("\\t%ld", (long){0}+0);
    #else
        printf("\\tno");
    #endif
    #ifdef {1}
        pr_pathconf("\\t", argv[1], {1});
    #else
        printf("\\tno\\n");
    #endif
'''.format(*l))

if __name__ == "__main__":
    import sys
    make(sys.argv[1], sys.argv[2])

