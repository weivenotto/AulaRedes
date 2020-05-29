#include <arpa/inet.h> //inet_addr
#include <stdio.h>
#include <string.h> //strlen
#include <sys/socket.h>
#include <unistd.h> // close

int main(int argc, char *argv[]) {
  int socketDesc;
  struct sockaddr_in server;

  socketDesc = socket(AF_INET, SOCK_STREAM, 0);

  if (socketDesc == -1) {
    printf("Não foi possivel criar o socket.\n");
    return 1;
  }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY; /*escute em qualquer IP da maquina */
    server.sin_port = htons(8888);

    if(bind(socketDesc, (struct sockaddr *) &server, sizeof(server)) < 0){
        printf("Erro ao fazer o bind\n");
        return 1;
    }
    printf("bind efetuado.\n");
    return 0;
}