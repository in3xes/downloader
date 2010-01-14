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
#include <time.h>

#define MAXSTRING	255
#define MAXBUFFER	1023
//#define DEBUG

typedef struct 
{
	char *url;
	char host[MAXSTRING];
	char path[MAXSTRING];
	char filename[MAXSTRING];
	char header[MAXSTRING];
	int status;
} downloader;

int tcp_connect(downloader *object, int port);
void download(int fd, downloader *object);
void parse(char *url, downloader *object);
void host(char *url, downloader *object);
double gettime();
void remove_proto(char *url,char *url_final);
void http_status(downloader *object);
void redirect(downloader *object);
