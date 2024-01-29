/*Authour : Lokhande */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

short portno;
int main(int argc,char *argv[])
{

int sock,i;
char buffer[512];
int addrlength,msglength, msgrecv;
int no_of_bytes;
struct sockaddr_in servaddr, cliaddr;

if(argc != 4)
{

 printf("Usage: client <portno> <hostname> <message>\n");
 exit(1);
}


if ( (sock = socket(AF_INET,SOCK_DGRAM,0)) < 0)
{
   perror("CLIENT: socket");
   exit(1);
}

  
cliaddr.sin_family = AF_INET;
cliaddr.sin_port=  htons(0);
cliaddr.sin_addr.s_addr =  htonl(0L);

if ( bind(sock, (struct sockaddr*)&cliaddr, sizeof(cliaddr) ) < 0) 
{
     perror("CLIENT:bind");
    exit(1);
}

 servaddr.sin_family = AF_INET;
 portno = atoi(argv[1]);
 servaddr.sin_port=htons(portno);
 servaddr.sin_addr.s_addr=inet_addr(argv[2]);

no_of_bytes = sendto(sock, argv[3], strlen(argv[3]), 0, 
		(struct sockaddr *)&servaddr, sizeof(servaddr) ); 
if ( no_of_bytes < 0)
{
	perror("\nCLIENT: send to error\n");
	exit(1);
}
printf("\t\tTALKER\n");
printf("\t\t------\n");
printf("send %d bytes to %s\n",no_of_bytes,inet_ntoa(servaddr.sin_addr));

return 0;
}
