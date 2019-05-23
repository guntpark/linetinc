#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <arpa/inet.h>

typedef struct _myInfo {
    int number;
    char name[14]; //uint_8 uint_16 char 9
} MyInfo;

typedef struct _myInfoEx {
    int numEx;
    uint8_t ui;
    uint16_t uii;
    char fill[9];
} InfoExtra;

void printinfo(MyInfo* xxx)
{
    printf ("test01() %d\n", xxx->number);
    int i = 0;
    for (; i < 14; i++)
    {
        printf(" %d ", xxx->name[i]);
    }
    printf("\n");
}

int main()
{
    char *string01 = "1234";
    char *string02 = "1234";


    //network bytes order (string to int)
    unsigned long convert_addr = inet_addr(string01);
    printf("> %lx \n", convert_addr);

    //atoi
    printf("> %d \n", atoi(string02));
        


    printf("size comp : %d vs %d\n", sizeof(MyInfo), sizeof(InfoExtra));


    InfoExtra *dts;

    dts = malloc(sizeof(InfoExtra));
    if(dts == NULL)
         return 0;

    memset (dts, 0, sizeof(InfoExtra));
    dts->numEx= 11;
    dts->ui = 21;
    dts->uii = 31;

    printinfo((MyInfo *) dts);


    free(dts);

    return 0;
}
