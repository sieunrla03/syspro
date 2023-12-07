#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void alarm_handler(int signum) {
   printf("Alarm clock \n");
   exit(0);
}

int main() {
   signal(SIGALRM, alarm_handler);
   alarm(5);

   printf("loop start \n");
   int seconds = 0;
   while (1) {
      sleep(1);
      printf("%d second\n", ++seconds);
   }

   return 0;
}
