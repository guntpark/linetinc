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

	struct sockaddr_in serv_adr;

	if(argc != 3)
	{
		printf("Usage : %s <ip> <port>", argv[0]);
		exit(1);
	}

	//socket()
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
    int recv_len, recv_cnt;
	for(; i < 3; i++)
	{
		str_len = write(sock, sendMsg[i], strlen(sendMsg[i]));
		//str_len = read(sock, message, BUF_SIZE - 1);
		//message[str_len] = 0;
	    //printf("Massage from [%s]!", message);
	    //korea pc

        recv_len = 0;
        while (recv_len < str_len)
        {
            recv_cnt = read(sock, message, BUF_SIZE - 1);
            if(recv_cnt == -1)
            {
		        fprintf(stderr, "read error()\n"); exit(1);
            }
            recv_len += recv_cnt;
            message[recv_len] = 0;
            printf("Massage from [%s]!\n", message);
        }
	}

	close(sock);
	return 0;
}	
