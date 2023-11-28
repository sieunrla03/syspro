#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char *argv[]) {
    char *env_var_name = NULL;
    extern char **environ;

    for (int opt; (opt = getopt(argc, argv, "e:ugiip")) != -1;) {
        switch (opt) {
            case 'e':
                env_var_name = optarg;
                if (env_var_name != NULL) {
                    char *env_var_value = getenv(env_var_name);
                    if (env_var_value != NULL) {
                        printf("%s=%s\n", env_var_name, env_var_value);
                    } else {
                        fprintf(stderr, "error\n");
                        return EXIT_FAILURE;
                    }
                } else {
                    fprintf(stderr, "error2\n");
                    return EXIT_FAILURE;
                }
                break;
            case 'u': {
                struct passwd *user_info = getpwuid(getuid());
                printf("My Realistic User ID: %d(%s)\n", getuid(), user_info->pw_name);
                printf("My Valid User ID: %d(%s)\n", geteuid(), user_info->pw_name);
                break;
            }
            case 'g': {
                struct passwd *user_info = getpwuid(getuid());
                printf("My Realistic Group ID: %d(%s)\n", getgid(), user_info->pw_name);
                printf("My Valid ID: %d(%s)\n", getegid(), user_info->pw_name);
                break;
            }
            case 'i':
                printf("my process number: [%d]\n", getpid());
                break;
            case 'p':
                printf("my parent's process number: [%d]\n", getppid());
                break;
            default:
                for (char **env = environ; *env != NULL; ++env) {
                    printf("%s\n", *env);
                }
        }
    }

    return 0;
}

