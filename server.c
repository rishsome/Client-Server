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
} 