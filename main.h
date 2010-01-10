/*									
(c) Pradeepkumar Gayam<deepu.aprjc@gmail.com>		*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

#define MAXSTRING	255
#define MAXBUFFER	5047

int tcp_connect(char *host, int port);
void download(int fd, char *path, char *filename);
