/*
 *	@file	: server.c
 *	@Aim	: Server program that accept connection from clients and do
 *		  lowercase to uppercase conversion of received data from client
 *	@Author	: Gaurang
 *	@Date	: 26 Oct 2017
*/

#include<stdio.h>
#include<netinet/in.h>
#include<errno.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>		/*	memset()		*/
#include<stdlib.h>		/*	exit()  & EXIT_FAILURE	*/
#include<unistd.h>		/*	read() & write()	*/
#include<arpa/inet.h>		/*	inet_addr()		*/
#include<ctype.h>		/*	isdigit()		*/

/* backlog affects is how many incoming connections can queue up if application
isn't accept()ing connections as soon as they come in. */
#define LISTEN_BACKLOG 50
#define CLIENT_NUMBER 100 /* maximum number of clients simultenuously served */
#define MSGSIZE 1024
#define handle_error(msg) do { perror(msg); exit(EXIT_FAILURE); } while (0)

int count;

int valid_number(char *s, uint32_t *data);
int argument_val(int argc, char *argv[], unsigned int *port);
void uppercase(char *buf, int str_len); /* lowercase to uppercase conversion */
void *connection_handler(void *ptr);

int main(int argc, char *argv[])
{
	char ip_add[16];
	unsigned int portNo;
	int socketfd, clientfd;
	/* argument check */
	if (argument_val(argc, argv, &portNo))
		exit(EXIT_FAILURE);
	strcpy(ip_add, argv[1]);
	/* socket: IPV4, TCP/IP */
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if (socketfd == -1)
		handle_error("Socket create error:");
	printf("Server socketfd: %d\n", socketfd);
	/* sockaddr_in structure: IPV4, port no and IP addr of server machine */
	struct sockaddr_in server_addr;
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(portNo);
	server_addr.sin_addr.s_addr = inet_addr(ip_add);
	/* bind:port to socket descreptor */
	if (bind(socketfd, (struct sockaddr *) &server_addr,
					sizeof(server_addr)) == -1) {
		close(socketfd);
		handle_error("Bind error:");
	}
	/* listen: */
	if (listen(socketfd, LISTEN_BACKLOG) == -1) {
		close(socketfd);
		handle_error("Listen fail error:");
	}
	/* accept: create client socket id */
	struct sockaddr_in client_addr;
	unsigned int size = sizeof(client_addr);
	pthread_t t[CLIENT_NUMBER];
	while (1) {
		while (count == CLIENT_NUMBER) /*waiting for the client close*/
			;
		clientfd = accept(socketfd, (struct sockaddr *) &client_addr,
					&size);
		if (clientfd == -1) {
			close(socketfd);
			handle_error("Accept fail error:");
		}
		printf("Client %d is connected\n", clientfd);
		pthread_create(&t[count++], NULL, connection_handler,
					(void *) &clientfd);
	}
	if (close(socketfd) == -1)
		handle_error("Server socket close error");
	printf("Server is closed\n");
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief:	received packets, do lowercase to upercase operationd and again
///		send packets to client
///@param :	void *ptr: pointer to argument data(client socket descreptor)
///@return:	void
/////////////////////////////////////////////////////////////////////////////*/
void *connection_handler(void *ptr)
{
	int len;
	int clientfd = *(int *) ptr;
	char buf[MSGSIZE] = "Hello from server\n";
	len = strlen(buf);
	if (send(clientfd, buf, len, 0) == -1) {
		count--;
		close(clientfd);
		fprintf(stderr, "Messeage send fail error\n");
		pthread_exit(NULL);
	}
//	memset(buf, 0, sizeof(buf));
	while (1) {
//		memset(buf, 0, sizeof(buf));
		len = recv(clientfd, buf, MSGSIZE, 0);
		if (len == -1) {
			count--;
			close(clientfd);
			fprintf(stderr, "Message receive fail error\n");
			pthread_exit(NULL);
		}
//		printf("%d len \n", len);
		if (len == 0)
			break;
		uppercase(buf, len);
		if (send(clientfd, buf, len, 0) == -1) {
			count--;
			close(clientfd);
			fprintf(stderr, "Message send fail error\n");
			pthread_exit(NULL);
		}
	}
	if (close(clientfd) == -1) {
		fprintf(stderr, "Client socket close error\n");
		pthread_exit(NULL);
	}
	printf("Client %d connection release successfully\n", clientfd);
	count--;
	pthread_exit(NULL);
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief:	check number of arguments, validate port number and assign it
///@param :	int argc: number of arguments
///		char *argv[]: command line argument pointer
///		unsigned int *port: store port number from argv[2] string
///@return:	void but store port number
/////////////////////////////////////////////////////////////////////////////*/
int argument_val(int argc, char *argv[], unsigned int *port)
{
	if (argc != 3) { /* arguments less or more */
		printf("To run the program follow below format\n");
		printf("./server.out <server_IP_addr> <port_number>\n");
		fprintf(stderr,
		"Error: too few command line argumennts to run he program\n");
		return -1;
	}
	if (valid_number(argv[2], port)) { /* number or not */
		fprintf(stderr, "Error: invalid input for the port number\n");
		return -1;
	}
	if (*port < 1024 || *port > 49151) { /* port number is reserve or not */
		fprintf(stderr, "Error: reserve port number\n");
		return -1;
	}
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief:	check given string is numeric or not
///@param :	char *s: string to check
///		uint32_t *data: if string numeric then converted number is
///		stored into data
///@return:	int: 0 on success othervise -1
/////////////////////////////////////////////////////////////////////////////*/
int valid_number(char *s, uint32_t *data)
{
	char *c = s;
	while (*c) {
		if (!isdigit(*c++))
			return -1;
	}
	*data = atoi(s);
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief:	Convert lowercase to upeercase letter
///@param :	char *s: string to convert
///		int str_len: string length
///@return:	void
/////////////////////////////////////////////////////////////////////////////*/
void uppercase(char *buf, int str_len)
{
	int i = 0;
	while (i != str_len) {
		if (islower(buf[i]))
			buf[i] = buf[i] - 32;
		i++;
	}
}
