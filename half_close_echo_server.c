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
	int serv_sock, clnt_sock;

	char message[BUF_SIZE];
	int str_len;

	struct sockaddr_in serv_adr, clnt_adr;
	socklen_t clnt_adr_size;

	if(argc != 2)
	{
		printf("Usage : %s <port>", argv[0]);
		exit(1);
	}

	//socket()
	if((serv_sock = socket(PF_INET, SOCK_STREAM, 0)) == -1)
	{
		fprintf(stderr, "socket error()\n"); exit(1);
	}
	
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(atoi(argv[1]));
	//bind()
	if(bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))== -1)
	{
		fprintf(stderr, "bind error()\n"); exit(1);
	}

	//listen()
	if(listen(serv_sock, 5) == -1)
	{
		fprintf(stderr, "listen error()\n"); exit(1);
	}

	//accept()
	clnt_adr_size = sizeof(clnt_adr);
	
	clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_size);
    if(clnt_sock == -1)
    {
	    fprintf(stderr, "accept error()\n"); exit(1);
	}

    char *sendmsg[] = 
    {
	    "1: Hello I'am Server",
	    "2: First Secret Data : 1",
	    "3: Second Secret Data : 2"
    };

    //send()
    int i = 0;
	for ( ;i < 3; i++)
    {
        printf ("%d :send %s : %d\n", i, sendmsg[i], strlen(sendmsg[i])); 
	    write(clnt_sock, sendmsg[i], strlen(sendmsg[i]));
    }

	shutdown(clnt_sock, SHUT_WR);

    read (clnt_sock, message, BUF_SIZE);
	printf("from client: %s ", message);
    
    close (clnt_sock);
    close (serv_sock);
    
	return 0;
}
