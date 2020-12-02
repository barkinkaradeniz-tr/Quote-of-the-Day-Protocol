#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <poll.h>

int main(int argc, char *argv[]) {
    /*struct sockaddr_storage their_addr;
    socklen_t addr_size;
    char ipstr[INET_ADDRSTRLEN];*/

    struct addrinfo hints, *res;
    int sockfd;
    int stillConnected;
    char *buf = calloc(8192,sizeof(char));
    char data;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    getaddrinfo(argv[1], argv[2], &hints, &res);
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    connect(sockfd, res->ai_addr, res->ai_addrlen);

    struct pollfd pfds[1];
    pfds[0].fd = sockfd;
    pfds[0].events = POLLIN;

    int i = 0;
    while ( 1 ){


        poll(pfds,1,-1);

        if (pfds[0].revents && POLLIN) {
            stillConnected = recv(sockfd, &data, 1, 0);
            if (stillConnected) {


                buf[i] = data;
                i++;

            } else {
                break;
            }
        }



    }

    for (int j = 0; j < i; j++) {
        printf("%c", buf[j]);
    }

    close(sockfd);
    free(buf);
    freeaddrinfo(res);
    return 0;
}
