#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fds[3];
    char *str = "Hello";

    char buf[100];
    pid_t pid;

    pipe (fds);
    pid = fork();

    if(pid == 0)
    {
        write (fds[1], str, sizeof(str));
    }
    else
    {
        read (fds[0], buf, 5);
        puts(buf);
        read (fds[2], buf, 5);
        puts(buf);
    }

    return 0;
}
