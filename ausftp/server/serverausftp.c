#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <boolean.h>

#include "serverdtp.h"

#define VERSION "1.0"
#define PTDEFAULT 21


int main(int argc, char const **argv ){
    int port;

    if(argc > 2){
        fprintf(stderr, "Error: numero de argumentos incorrectos\n");
        return 1;
    } else {
        port = PTDEFAULT; //Puerto default FTP
    }

    if(argc == 2){
        port = atoi(argv[1]);

    }

    if(port==0){
        fprintf(stderr, "Puerto inválido\n")
            return 1
    }

    printf("%d\n", port);

    //printf("Devuelve %d\n", check_credentials("pepe", "pepe"));

    printf("Devuelve %d\n", check_credentials("test", "pepe"));

    int mastersocket, slavesocket;
    struct sockaddr_in masteraddr, slaveaddr;
    socklen_t slaveaddrlen;

    masterscoket = socket(AF_INET, SOCK_STREAM, 0);

    masteraddr.sin_family = AF_INET;
    masteraddr.sin_addr.s_addr = INADDR_ANY;
    masteraddr.sin_port = htons(port);

    bind(mastersocket, (struct sockaddr *) &masteraddr, sizeof(masteraddr));

    listen(mastersocket, 5);

    while(true){
        slaveaddrlen = sizeof(slaveaddr);
        slavesocket = accept(mastersocket, (struct sockaddr *) &slaveaddr, &slaveaddrlen);

    }

    return 0;
}