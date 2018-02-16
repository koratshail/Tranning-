/*
 * @file  : client.c
 * @Aim   : client programe that open a file, send 1024 byte chunks of it to 
 *	    server for lowercase to uppercase conversion and store it to new
 *	    created file
 * @Author: Gaurang
 * @Date  : 27 Oct 2017
 */

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<time.h>

#define DESTPORT 3500 /* port number */
#define MSGSIZE 1024 /* data of 1024 byte chunks to be sent */

#define handleError(msg) do { perror(msg); exit(EXIT_FAILURE); } while (0)

int argumentCheck(int argc);

int main(int argc, char *argv[])
{
	/* argument check */
	if (argumentCheck(argc)) {
		printf("To run the program enter command as below\n");
		printf("./client.out <server_IP_addr> <file_to_convert>\n");
		fprintf(stderr,
		"Error: too few command line arguments to run the program\n");
		exit(EXIT_FAILURE);
	}

	FILE *fp, *fn;
	char serverIpAddr[16], fileName[20];
	strcpy(serverIpAddr, argv[1]); /* store IP addr */
	strcpy(fileName, argv[2]);

	/* file open */
	fp = fopen(fileName, "r"); /* file to convert */
	if (!fp)
		handleError(fileName);

	/* socket create */
	int sockfd;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (!sockfd)
		handleError("Socket create error:");
	printf("Socket id: %d\n", sockfd);

	/* struct sockaddr_in for server */
	struct sockaddr_in dest_addr;
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_port = htons(DESTPORT);
	dest_addr.sin_addr.s_addr = inet_addr(serverIpAddr);

	/* connect is non blocking api */
	if (connect(sockfd, (struct sockaddr *) &dest_addr,
	    sizeof(struct sockaddr))) {
		close(sockfd);
		handleError("Connection error:");
	}

	/* communication and file reading */
	char buf[MSGSIZE + 1];
	int len, c, i;
	time_t start, end;

	memset(buf, 0, sizeof(buf)); /* clear buffer */
	len = recv(sockfd, buf, MSGSIZE, 0);
	if ( len == -1) { /* msg from server */
		close(sockfd);
		handleError("Message receive fail error:");
	}
	printf("%s", buf);
	fn = fopen("converted_file.txt", "w+"); /* converted output file */

	start = time(NULL);
	while (c != EOF) {
		for (i = 0; i < MSGSIZE; ++i) {
			c = fgetc(fp);
			if (c == EOF) {
				buf[i] = '\0';
				break;
			}
			buf[i] = (char) c;
		}
		len = strlen(buf);
		if (send(sockfd, buf, len, 0) == -1) {
			close(sockfd);
			handleError("Message send fail error:");
		}
		len = recv(sockfd, buf, len, 0);
		if (len == -1) { /* msg from server */
			close(sockfd);
			handleError("Message receive fail error:");
		}
		fwrite(buf, len, 1, fn);
	}
	end = time(NULL);
	printf("Time consume to convert file: %lf seconds\n", difftime(end,start));
	if (close(sockfd) == -1)
		handleError("Client socket close fail error:");
	printf("Lowercase conversion of %s file is completed successfully\n",
		fileName);
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief:	check command line arguments
///@param :	int argc: number of arguments
///@return:	return 0 on success else return -1
/////////////////////////////////////////////////////////////////////////////*/
int argumentCheck(int argc)
{
	if (argc != 3)
		return -1;
	return 0;
}
