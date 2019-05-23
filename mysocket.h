#ifndef my_socket_h_
#define my_socket_h_


#define BUF_SIZE 10

char message[BUF_SIZE];
int serv_sock;
int clnt_sock;

void socket_create(char *portnm);

void client_accept();

#endif
