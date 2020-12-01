#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <stdbool.h>
#include <unistd.h>

#define MAXCHAR 512
#define BACKLOG 10

struct theText {
    char *line;
    int index;
    struct theText *next;
}theText_l;

char *getText(char* filename){

    static char line[MAXCHAR];
    int counter = 0;

    FILE *fp = fopen(filename , "r");

    if (fp == 0) {
        perror("Error opening the file");
        return (-1);
    }

    while (fgets(line, MAXCHAR, fp) != NULL) {
        counter++;
    }
    fclose(fp);


    FILE *fp2 = fopen(filename , "r");

    if (fp2 == 0) {
        perror("Error opening the file");
        return (-1);
    }
    for (int i = 0; i < (rand() % counter); i++) {
        fgets(line, MAXCHAR, fp2);
    }
    fclose(fp2);


    return line;
}

int main(int argc, char *argv[] ){

    struct addrinfo hints, *servinfo;
    struct sockaddr_storage their_addr;
    char *msg = getText(argv[1]);
    int sock_fd, new_fd;
    int len, bytes_sent;

    socklen_t addr_size;
    len = strlen(msg);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    getaddrinfo(NULL, argv[2], &hints, &servinfo);
    sock_fd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    bind(sock_fd, servinfo->ai_addr, servinfo->ai_addrlen);
    listen(sock_fd, BACKLOG);

    addr_size = sizeof(their_addr);
    new_fd = accept(sock_fd, (struct sockaddr *)&their_addr, &addr_size);

    for (int i = 0; i < len; i++) {
        bytes_sent = send(new_fd, &msg[i], 1, 0);
        if (bytes_sent == 0) {
            perror("Byte failed to send.");
        }
    }

    close(new_fd);
    close(sock_fd);

    freeaddrinfo(servinfo);
    return 0;
}


