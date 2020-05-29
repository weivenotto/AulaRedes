#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>

int main(int argc, char *argv[]){

    // weiven 
    //AF_INET - IPv4, SOCK_STREAM - tcp, 0 - IP
    int socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_desc == 1) {

        printf("Não foi possivel criar o socket");
        return 1;
    }

    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr("172.217.28.132"); /* converte IP para long */
    server.sin_family = AF_INET; /* ip v4 */
    server.sin_port = htons(80);

    /* conecta-se ao servidor */
    if (connect(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0)
    {
        printf("Erro ao conectar-se\n");
        return 1;
    }
    printf("Conectado.\n");

    return 0;
    
}
