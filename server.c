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

char *getText(char* filename){

    char *prefix = "../";
    char *path = malloc(MAXCHAR);
    static char line[MAXCHAR];
    strcpy(path, prefix);
    memcpy(path + 3, filename, sizeof(&filename));

    FILE *fp;
    fp = fopen(path , "r");

    if (fp == 0) {
        perror("Error opening the file");
        return(-1);
    }

    for (int i = 0; i < (31); i++) {
        fgets(line, MAXCHAR, fp);
    }

    fclose(fp);


    return line;
}

int main(int argc, char *argv[] ){

    struct addrinfo hints, *servinfo;
    int sock_fd, new_fd;
    struct sockaddr_storage their_addr;
    socklen_t addr_size;
    char *msg = getText(argv[1]);
    int len, bytes_sent;
    len = strlen(msg);
    printf("%s", msg);

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
    bytes_sent = send(new_fd, msg, len, 0);

    close(new_fd);
    close(sock_fd);

    freeaddrinfo(servinfo);
    return 0;
}


