#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include "mysocket.h"

void socket_create(char *portnm)
{

	if((serv_sock = socket(PF_INET, SOCK_STREAM, 0)) == -1)
	{
		fprintf(stderr, "socket error()\n"); exit(1);
	}
    
    struct sockaddr_in serv_adr ;
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(atoi(portnm));
	
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
}

void client_accept()
{
	struct sockaddr_in clnt_adr;
	socklen_t clnt_adr_size;
	
    clnt_adr_size = sizeof(clnt_adr);
    int str_len, i;
	for (i = 0; i < 5; i++)
	{
		clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_size);
		if(clnt_sock == -1)
		{
			fprintf(stderr, "accept error()\n"); exit(1);
		}
		else
		{
			printf("connected Client %d \n", i + 1);
		}

		//send()
		while ((str_len = read (clnt_sock, message, BUF_SIZE)) != 0)
			write(clnt_sock, message, str_len);

		close(clnt_sock);
	}
}
