#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include "mysocket.h"


int main(int argc, char *argv[])
{
    if(argc != 2)
	{
		printf("Usage : %s <port>", argv[0]);	exit(1);
	}

    
    socket_create(argv[1]);

    client_accept();
	
	close (serv_sock);

	return 0;
}
