// receiving from client 
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
int sockfd,length,i;
struct sockaddr_in recv1,recv2;
int MAXLEN;
char buf[100];

sockfd=socket(AF_INET,SOCK_DGRAM,0);
 recv1.sin_family=AF_INET;
 recv1.sin_addr.s_addr=INADDR_ANY;
 recv1.sin_port=6000;


 i=bind(sockfd,(struct sockaddr *)&recv1,sizeof(recv1));
 printf("Socket Return Value and Bind Return Value : %d and %d\n",sockfd,i);

 length=sizeof(recv2);
int k= recvfrom(sockfd,buf,MAXLEN-1,0,(struct sockaddr*)&recv2,&length);
buf[k+1]='\0';
  printf(" Received string is : %s ",buf);


close(sockfd);


 }
