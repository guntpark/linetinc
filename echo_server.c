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
	int str_len, i;

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
	close (serv_sock);

	return 0;
}
