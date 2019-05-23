#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main ()
{
    
    pid_t pid = fork();


    if(pid == 0)
    {
        printf("Hi, I am a child procee");
    }
    else
    {
        printf("Child Process ID : %d\n", pid);
        //sleep (30);
    }


    int status;
    if(pid == 0)
    {
        puts ("End Child Process");
        return 3;
    }
    else
    {
        wait(&status);
        if(WIFEXITED(status))
           printf("Child Process : %d \n", WEXITSTATUS(status));

        puts ("End Parent Process");
    }

    return 0;
}
