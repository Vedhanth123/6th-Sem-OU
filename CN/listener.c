/*Authour : LOKHANDE */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

short portno;
int main(int argc, char *argv[])
{
int sockmain,i;
char  buffer[512];
struct sockaddr_in servaddr,cliaddr;
int addrlength,msglength;

if (argc != 2)
{
	printf(" USAGE: Listener <portno> " );
        exit(1);
}

if ((sockmain = socket(AF_INET,SOCK_DGRAM, 0)) <0) 
{
   perror("server socket");
   exit(1);
}

portno = atoi(argv[1]);
servaddr.sin_family = AF_INET;
servaddr.sin_port = htons(portno);
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

i = sizeof(servaddr);

if (bind(sockmain, (struct sockaddr *)&servaddr, i) < 0) 
{
  perror("bind");
  exit(1);
}

addrlength = sizeof(cliaddr);
msglength=recvfrom(sockmain, (char *)buffer, sizeof(buffer),
	 0, (struct sockaddr*)&cliaddr, (socklen_t *)&(addrlength) ) ; 

if (msglength < 0)
{
    perror("recieve from error\n");
    exit(1);
}

printf("\t\tLISTENER\n");
printf("\t\t--------\n");
printf("Got a packet from %s\n ",inet_ntoa(cliaddr.sin_addr));
printf("Packet is %d bytes long\n",msglength);
printf("Packet contains %s\n",buffer);
return 0;
}

