#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

void do_service(int sockfd);
void nano_sleep(double val);

int main(int argc, const char *argv[])
{
    int peerfd = socket(PF_INET, SOCK_STREAM, 0);
    if(peerfd == -1)
        ERR_EXIT("socket");

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof addr);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //localhost
    addr.sin_port = htons(8976);
    socklen_t len = sizeof addr;
    if(connect(peerfd, (struct sockaddr *)&addr, len) == -1)
        ERR_EXIT("Connect");

    do_service(peerfd);


    return 0;
}



void do_service(int sockfd)
{
    //const int kSize = 1024;
    #define SIZE 1024
    char sendbuf[SIZE + 1] = {0};
    int i;
    for(i = 0; i < SIZE; ++i)
        sendbuf[i] = 'a';

    int cnt = 0; //次数
    while(1)
    {
        int i;
        for(i = 0; i < 10; ++i)
        {
            write(sockfd, sendbuf, SIZE);
            printf("count = %d, write %d bytes\n", ++cnt, SIZE);
        }
        nano_sleep(4);

        memset(sendbuf, 0, sizeof sendbuf);
    }
}

void nano_sleep(double val)
{
    struct timespec tv;
    tv.tv_sec = val; //取整
    tv.tv_nsec = (val - tv.tv_sec) * 1000 * 1000 * 1000;

    int ret;
    do
    {
        ret = nanosleep(&tv, &tv);
    }while(ret == -1 && errno == EINTR);
}



