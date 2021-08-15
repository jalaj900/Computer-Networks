#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<stdio.h>
int main()
{
int sockfd=socket(AF_INET,SOCK_DGRAM,0);
if(sockfd>0)
{
printf("\n--SOCKET CREATED SUCCESSFULLY---");
printf("\n socket value: %d",sockfd);
}
else
printf("\n--SOCKET  NOT CREATED ---");

struct sockaddr_in server;
server.sin_family =AF_INET;
server.sin_port = htons(5000);
server.sin_addr.s_addr = inet_addr("127.0.0.1");



int bindfd = bind(sockfd, (const struct sockaddr*)&server,sizeof(server));
if(bindfd==0)

   printf("\n BIND SUCCESSFUL");
   else
   printf("\n BIND UNSUCCESSFUL ");
  ssize_t sendto( int sockfd,const void *buf,size_t len,int flags,const struct sockaddr *dest_addr, socklen_t addrlen);

}