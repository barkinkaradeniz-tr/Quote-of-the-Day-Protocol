#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <stdbool.h>
#include <unistd.h>
#include<time.h>

#define MAXCHAR 5120
#define BACKLOG 10
size_t howLong = 0;

struct theText {
    char *line;
    int index;
    struct theText *next;
}theText_l;

char *getText(char* filename){

    char *line = (char *)malloc(MAXCHAR * sizeof(char));
    size_t len1 = MAXCHAR;
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


    srand(time(0));
    for (int i = 0; i < rand() % counter; i++) {
        howLong = getline(&line, &len1, fp2);
    }
    fclose(fp2);


    return line;
}

int main(int argc, char *argv[] ){

    struct addrinfo hints, *servinfo;
    struct sockaddr_storage their_addr;
    int sock_fd, new_fd;
    int len, bytes_sent;
    int rv;
    char *msg = getText(argv[2]);

    socklen_t addr_size;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if ((rv = getaddrinfo(NULL, argv[1], &hints, &servinfo)) != 0) {
        fprintf(stderr,"getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }
    sock_fd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (-1 == bind(sock_fd, servinfo->ai_addr, servinfo->ai_addrlen)) {
        close(sock_fd);
        perror("server : bind");
    }
    if (servinfo == NULL) {
        fprintf(stderr, "server: failed to bind\n");
        exit(1);
    }

    if(listen(sock_fd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    addr_size = sizeof(their_addr);
    new_fd = accept(sock_fd, (struct sockaddr *)&their_addr, &addr_size);

    for (int i = 0; i < ((int)howLong); i++) {

        bytes_sent = send(new_fd, &msg[i], 1, 0);

    }

    close(new_fd);
    close(sock_fd);

    freeaddrinfo(servinfo);
    return 0;
}


