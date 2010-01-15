/*A simple downloader						*\
*								*
\*(C) 2010 Pradeepkumar Gayam<deepu.aprjc@gmail.com>		*/

//Main Header
/*
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License with
  the Debian GNU/Linux distribution in file /usr/doc/copyright/GPL;
  if not, write to the Free Software Foundation, Inc., 59 Temple Place,
  Suite 330, Boston, MA  02111-1307  USA
*/

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
