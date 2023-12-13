#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void alarmHandler(int signo);

int main() {
    struct sigaction sa;
    sa.sa_handler = alarmHandler;
    sa.sa_flags = 0;
    sigaction(SIGALRM, &sa, NULL);

    alarm(5);
    printf("loop start\n");
    int seconds = 0;

    while (1) {
        sleep(1);
        printf("%d second\n", ++seconds);
    }

    printf("\n");
}

void alarmHandler(int signo) {
    printf("wake up\n");
    exit(0);
}

