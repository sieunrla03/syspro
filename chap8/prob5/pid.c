#include <stdio.h>
#include <unistd.h>

int main()
{    
     printf("my proccess number : [%d] \n", getpid());
     printf("my parents number : [%d] \n", getppid());
}

