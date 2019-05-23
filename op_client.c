#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

int main(int argc, char *argv)
{
    int sock;
    char opmsg[BUF_SIZE];
    int result, opnd_cnt, i;
    struct sockaddr_in serv_addr;
    
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

    //data yaritori
    fputs("operand count : ", stdout);
    scanf ("%d", &opnd_cnt);
    opmsg[0] = (char) opnd_cnt;

    return 0;
}
