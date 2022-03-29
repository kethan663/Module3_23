#include<unistd.h>
#include "stdio.h"
#include <stdlib.h>

int main()
{
    printf("Welcome");
    int ret = fork();
    if(ret >0)
    {
        for(int i=0;i<100;i++)
        { 
            sleep(1); 
        printf("Welcome from Parents, PID = %d, PPID = %d, ret = %d\n",getpid(), getppid(), ret);
        }
    }
    else if(0 == ret)
    {
        printf("Welcome from Child, PID = %d, PPID = %d, ret = %d\n",getpid(), getppid(), ret);
    }
    else
    {
        perror("fork");
        exit(0);
    }
    
}