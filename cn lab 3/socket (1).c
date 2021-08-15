#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
int fd,bd1,len;
char buf[100];
       fd=socket(AF_INET, SOCK_DGRAM,0);
       
       
       struct sockaddr_in x1;
        x1.sin_family = AF_INET;
        x1.sin_port = htons(6000); /* htons() is needed again */
        x1.sin_addr.s_addr =inet_addr("127.0.0.1"); 
 

  //      bd1=bind(fd, (const struct sockaddr *) &x1,sizeof x1);
                printf("Enter Message");
                gets(buf);
                len=strlen(buf);
        sendto(fd, buf, len, 0,(const struct sockaddr *) &x1, sizeof x1);
                
        close(fd);
       }

