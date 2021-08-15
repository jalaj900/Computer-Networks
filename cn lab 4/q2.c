//Client:
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
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0); //socket function returns 0,1 only

    int inputint; // number to be checked as palindrome

    char buffer[50], input[10];

    struct sockaddr_in servaddr; //object creation of sockaddr_in

    printf("Enter a number : ");    //enter no. to be checked
    scanf("%d", &inputint);        //storing number 
    
    sprintf(input, "%d", inputint);  //sprintf stores the result in string

//checking wheather socket is created sucessfully or not

    if (sockfd  < 0)
     {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
     }


    memset(&servaddr, 0, sizeof(servaddr));     // array of 0 same as size of the struct sockaddr

//setting the value of members of ths struct sockaddr_in 

    servaddr.sin_family = AF_INET;                      // set to AF_INET -> used for internet connection
    servaddr.sin_port = htons(6000);                    //settind the port number (htons ->converts port no. to short)
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 


    int n, len;

//setting up the sendto function   

    sendto(sockfd, ( const char *)input,   strlen(input)   ,     0      ,  (const struct sockaddr *)&servaddr, sizeof(servaddr));
                    //pointer to the      ,len of message  ,flags=0  ,    destination IP and port    ,       size of servaddr
                    //data to be sent

//setting up recvfrom() function

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
    int sockfd, i, inputint, rev = 0;

    char buffer[10], output[50];

    struct sockaddr_in servaddr, cliaddr;

    //sockect creation and confirmation of sucess
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    memset(&cliaddr, 0, sizeof(cliaddr));
    
    //strcut servaddr menbers vales

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(6000);

    //bind(sockfd. (const strcut sockaddr*) &servaddr ,sizeof(servaddr))

    // check sucess of bind()  function
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    int len, n;

    len = sizeof(cliaddr);

    n = recvfrom(sockfd, buffer, 101, 0, (struct sockaddr *)&cliaddr, &len);

    buffer[n] = '\0';

    sscanf(buffer, "%d", &inputint);


    for (i = inputint; i != 0; i /= 10)
    {
        rev *= 10;
        rev += i % 10;
    }
    printf("%d\n", rev);

    if (rev == inputint)
    {
        strcpy(output, "It is a palindrome");
    }
    else
    {
        strcpy(output, "It is not a palindrome");
    }

    sendto(sockfd, output, strlen(output), 0, (const struct sockaddr *)&cliaddr, len);
    
    close(sockfd);
    return 0;
}
