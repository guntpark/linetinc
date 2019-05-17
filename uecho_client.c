#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

char *sendMsg[] = 
{
	"I am GT Park",
	"I live in Tokyo soon",
	"I am allways happy for CL and JS"
};

int 
main(int argc, char *argv[])
{
	int sock;

	char message[BUF_SIZE];
	int str_len;

	struct sockaddr_in serv_adr, from_adr;

	if(argc != 3)
	{
		printf("Usage : %s <ip> <port>", argv[0]);
		exit(1);
	}

	//socket()
	if((sock = socket(PF_INET, SOCK_DGRAM, 0)) == -1)
	{
		fprintf(stderr, "socket error()\n"); exit(1);
	}
	
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_adr.sin_port = htons(atoi(argv[2]));
    
    int i = 0;
    socklen_t adr_sz;
	for(; i < 3; i++)
	{
		sendto(sock, sendMsg[i], strlen(sendMsg[i]), 0,
                 (struct sockaddr*)&serv_adr, sizeof(serv_adr));

        adr_sz = sizeof(from_adr);

        str_len = recvfrom(sock, message, BUF_SIZE, 0,
                        (struct sockaddr*)&from_adr, &adr_sz);
        message[str_len] = 0;
        printf("Massage from [%s]!\n", message);
	}

    close (sock);
    return 0;
}
