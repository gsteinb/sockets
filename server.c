#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#define PORT 80
#define LISTEN_BACKLOG 50

// PROTOTYPES
struct sockaddr_in init_sockaddr(struct sockaddr_in);


/**
 * initiliaser for sockaddr struct
 * @param sockaddr struct to initialise
 * @returns initialised struct
 */
struct sockaddr_in init_sockaddr(struct sockaddr_in sockaddr) {
    // clear struct
    memset(&sockaddr, 0, sizeof(struct sockaddr_in));
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_addr.s_addr = INADDR_ANY;
    sockaddr.sin_port = htons(PORT);
    return sockaddr;
}

int main(int argc, char *argv[]) {

    int sockfd, n;
    char buffer[256];
    struct sockaddr_in serv_addr, client_addr;

    sfd = socket(AF_INET, SOCK_STREAM, 0);
    // error check
    if (sockfd == -1) {
        perror("Error opening socket\n");
    }
    // init struct
    serv_addr = init_sockaddr(serv_addr);
    if (bind(sfd, (struct sockaddr *) &serv_addr, sizeof(struct sockaddr_in)) == -1) {
        perror("Error binding\n");
    }
    if (listen(sfd, LISTEN_BACKLOG) == -1) {
        perror("Error listening\n");
    }
    client_len = sizeof(client_addr);
    cfd = accept(sfd, (struct sockaddr *) &client_addr, &client_len);

    if (cfd == -1) {
        perror("Error accepting connection\n");
    }

    n = read(cfd, buffer, 255);
    if (n == -1) {
        perror("Error reading from cfd\n");
    }
    printf("message: %s\n", n);
    n = write(cfd, "Hello thank you\n", 25);
    if (n < 0) {
        perror("Error writing to cfd\n");
    }

    return 0;
}
