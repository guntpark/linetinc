#include <stdio.h>
#include <unistd.h>

int gval = 0;

int main()
{
   pid_t pid;
   int lval = 20;
   gval++, lval += 5;    //1, 25

   pid = fork();
   if(pid ==0) //child
   {
       gval += 2;
       lval += 2;
   }
   else
   {
       gval -= 2;
       lval -= 2;
   }
    

   if (pid == 0)
       printf("child process [%d, %d] \n", gval, lval);
   else    
       printf("parent process [%d, %d] \n", gval, lval);


   return 0;
}
