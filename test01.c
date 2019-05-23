#include <stdio.h>
#include <string.h>

int main()
{
     char *sendMsg[] =
     {
     "I am GT Park",
     "I live in Tokyo soon",
     "I am allways happy f(r CL and JS"
     };

    int i = 0;
    for(; i < 3; i++)
	{
        int j = 0;    
		for (; j < strlen(sendMsg[i]); j++)
        {
		    printf("%c", sendMsg[i][j]);
        }
    }
}
