#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string>

const char* HOST = "127.0.0.1";
const int PORT = 9900;

int error(std::string msg)
{
  perror(msg.c_str());
  return 1;
}

int sendData(std::string msg)
{
  int sockfd, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  server = gethostbyname(HOST);
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
  {
    error("ERROR opening socket");
  }
  if (server == NULL)
  {
    fprintf(stderr, "ERROR, no such host\n");
    exit(0);
  }
  bzero((char *)&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(PORT);
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  {
    error("ERROR connecting");
  }
  n = write(sockfd, msg.c_str(), strlen(msg.c_str()));
  if (n < 0)
  {
    error("ERROR writing to socket");
  }
  close(sockfd);
  return 0;
}
