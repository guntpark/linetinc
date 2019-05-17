#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

int 
main(int argc, char *argv[])
{
	int sock;

	char message[BUF_SIZE];
	int str_len;

	struct sockaddr_in serv_adr;

	if(argc != 3)
	{
		printf("Usage : %s <ip> <port>", argv[0]);
		exit(1);
	}

	if((sock = socket(PF_INET, SOCK_STREAM, 0)) == -1)
	{
		fprintf(stderr, "socket error()\n"); exit(1);
	}
	
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_adr.sin_port = htons(atoi(argv[2]));

	if (connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)
	{
		fprintf(stderr, "connect error()\n"); exit(1);
	}
	else
	{
		puts("connected.........");
	}
	
	int i = 0;
    str_len = read(sock, message, 1024);
    //{
        //printf("read len : [%d]!\n", str_len);
    //}
   
    //for (; i < str_len; i++)
       // printf("Massage from [%c]!\n", message[i]);
   
    printf("Message from server [%s] \n", message);

    write(sock, "Thanks" , strlen("Thanks"));
    
	close(sock);
	return 0;
}	
