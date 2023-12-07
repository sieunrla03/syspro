#include <stdio.h>
#include <signal.h>
void alarmHandler();
int main( )
{
   signal(SIGALRM, alarmHandler);
   alarm(5);    
   printf("loop start \n");
   int seconds = 0;
   while (1) {
      sleep(1);
      printf("%d second \n", ++seconds);
   }
   printf(" \n");
}
void alarmHandler(int signo)
{
   printf("wake up\n");
   exit(0);
}

