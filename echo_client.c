#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 100 

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
	//int str_len;

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
    int send_len = 0;
    //int recv_len, recv_cnt;
	for(; i < 3; i++)
	{
        //send_len = 0;
        //recv_len = 0;
        int j = 0;    
		for (; j < strlen(sendMsg[i]); j++)
        {
            //printf("%c", sendMsg[i][j]);
                
		    //send_len += write(sock, &sendMsg[i][j], 1);
		    send_len += sendto(sock, &sendMsg[i][j], 1, 0, (struct sockaddr*)&serv_adr, sizeof(serv_adr));
        }

        printf("first send_len : %d\n", send_len);
        printf("\n\n\n\n");

        
        
        //korea pc

        /*    
		str_len = write(sock, sendMsg[i], strlen(sendMsg[i]));
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
        */
	}
    read(sock, message, BUF_SIZE - 1);
	printf("Massage from [%s]!", message);
	    


	close(sock);
	return 0;
}	
