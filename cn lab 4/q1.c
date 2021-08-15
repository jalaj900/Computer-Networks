//Client
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
int main()
{
    int sockfd;
    char buffer[101], input[101];
    struct sockaddr_in servaddr;
    printf("Enter a string : ");
    scanf("%[^\n]s", input);
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6000);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    int n, len;
    sendto(sockfd, (const char *)input, strlen(input), 0, (const struct sockaddr *)&servaddr,
           sizeof(servaddr));
    n = recvfrom(sockfd, buffer, 101, 0, (struct sockaddr *)&servaddr, &len);
    buffer[n] = '\0';
    printf("Server : %s\n", buffer);
    close(sockfd);
    return 0;
}

//Server:
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
int main()
{
    int sockfd, i;
    char buffer[101];
    char output[101];
    struct sockaddr_in servaddr, cliaddr;
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(6000);
    if (bind(sockfd, (const struct sockaddr *)&servaddr,
             sizeof(servaddr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    int len, n;
    len = sizeof(cliaddr);
    n = recvfrom(sockfd, buffer, 101, 0, (struct sockaddr *)&cliaddr, &len);
    buffer[n] = '\0';
    for (i = 0; i < n; i++)
    {
        output[i] = toupper(buffer[i]);
    }
    output[n] = '\0';
    sendto(sockfd, output, strlen(output), 0, (const struct sockaddr *)&cliaddr, len);
    close(sockfd);
    return 0;
}
