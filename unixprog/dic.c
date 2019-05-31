#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include "ourhdr.h"

void test01(int argc, char *argv[]);
void test02();
void test03();
void test04();

int main(int argc, char *argv[])
{
    test04();



    exit(0);
}

void test04()
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%% ");
        while (fgets(buf, MAXLINE, stdin) != NULL) {
            buf[strlen(buf) - 1] = 0; //replace '\n' to '\0'
            printf("[%s] : %d\n", buf, strlen(buf));

            if((pid = fork()) < 0) {
                fprintf(stderr, "fork() error");
                exit(1);
            }
            else if (pid == 0) {
                //child
                execlp(buf, buf, (char *)0);
                err_ret("couldn't execute: %s", buf);
                exit(127);
            }
            
            if( (pid = waitpid(pid, &status, 0)) < 0)
                    err_sys("waitpid error");
            printf("%% ");

        }
}


void test03()
{
    int c;
    while ((c = getc(stdin)) != EOF) {
        if (putc (c, stdout) == EOF) 
            fprintf(stderr, "output error");
    }

    if (ferror(stdin))
        fprintf(stderr, "input error");

}

void test02()
{
#define BUFFSIZE 8192        
    int n;
    char buf[BUFFSIZE];

    while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
            if(write(STDOUT_FILENO, buf, n) != n)
                    fprintf(stderr, "write error");

    if (n < 0)
       fprintf(stderr, "read error");     
}

void test01(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if(argc != 2)
    {
        fprintf(stderr, "a single argument (the directory name) is required\n");
        exit(1);
    }

    if( (dp = opendir (argv[1])) == NULL)
    {
        fprintf(stderr, "can't open %s\n", argv[1]);

        exit(1);
    }

    while ( (dirp = readdir(dp)) != NULL)
    {
        printf("%s\n", dirp->d_name);
    }

    closedir(dp);


}
