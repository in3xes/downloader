/*									
(c) Pradeepkumar Gayam<deepu.aprjc@gmail.com>		*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

#define MAXSTRING	255
#define MAXBUFFER	5047
#define DEBUG

typedef struct 
{
	char *url;
	char host[MAXSTRING];
	char *path;
	char filename[MAXSTRING];
} downloader;

int tcp_connect(char *host, int port);
void download(int fd, char *path, char *filename);
void parse(char *url, downloader *object);
void host(char *url, downloader *object);

//void parse(char *url);
//void host(char *url);


