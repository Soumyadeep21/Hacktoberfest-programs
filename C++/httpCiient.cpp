#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]){

    char *address;
    address = argv[1];

    int client_socket;
    client_socket = socket(AF_INET, SOCK_STREAM,0);

    // specify an address for the socket
    struct sockaddr_in remote_address;
    remote_address.sin_family = AF_INET;
    remote_address.sin_port = htons(8001);
    inet_aton(address, &remote_address.sin_addr.s_addr);

    int connection_status = connect(client_socket, (struct sockaddr *) &remote_address, sizeof(remote_address));
    if(connection_status == -1){
        printf("There was an error making a connection to the remote server\n\n");
    }

    // char request[] = "GET / HTTP/1.1\r\n\n";
    // char response[4096];
    // send(client_socket, request, sizeof(request), 0);
    // recv(client_socket, &response, sizeof(response), 0);

    // printf(response);

    close(client_socket);

    return 0;
}