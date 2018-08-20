/* A simple server in the internet domain using TCP 
  The Port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
	perrror(msg);
	exit(1);
}

int main(int argc, char *argv[])
{
	int sockfd, newsockfd, portno;
	socklen_t, clilen;
	char buffer[225];
	struct sockaddr_in serv_addr, cli_addr;
	int n;
	if(argc < 2)
	{
		fprintf(stderr, "ERROR, no port provided\n");
		exit(1);
	}
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
		error("ERROR opening socket");
	bzero((char *) &serv_addr, sizeof(serv_addr));
	portno= atoi(argv[1]);
	serv_addr.sin_family= AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);

	if(bind(sockfd,(struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		error("Binding Failed");

	listen(sockfd, 5);
	clilen= sizeof(cli_addr);

	newsockfd =accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

	if(newsockfd < 0)
		error("ERROR on Accept");

	while(1)
	{
		bzero(buffer, 256);
		n= read(newsockfd, buffer, 255);
		if(n<0)
			error("Error on reading");
		printf("CLient : %s\n", buffer);
		bzero(buffer, 255);
		fgets(buffer, 255, stdin);

		n= write(newsockfd, buffer, strlen(buffer));
		if(n<0)
			error("Error on writing.");
		int i= strncmp("Bye", buffer, 3);
		if(i==0)
			break;
	}
	close(newsockfd);
	close(sockfd);
	return 0
;
 } 