/*A simple downloader						*\
*								*
\*(C) 2010 Pradeepkumar Gayam<deepu.aprjc@gmail.com>		*/

//Network stuff
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


#include "download.h"

int tcp_connect(downloader *object, int port)
{
	struct addrinfo *local;
	struct sockaddr_in host;
	struct hostent *host_det;
	int fd;
	
	if(!(host_det = gethostbyname(object->host)))
		printf("Error in finding hostname..!!\n");
	
//	printf("Info: %i\n",*host_det->h_name);	
	
	if(fd = socket(AF_INET, SOCK_STREAM, 0))
	{
#ifdef DEBUG
		printf("Socket created..!\n");
#endif
	}
	else
		printf("Error in creating socket..!\n");
	
	struct addrinfo tmp;
	memset(&tmp, 0, sizeof(struct addrinfo));
	tmp.ai_family = AF_INET;
	tmp.ai_socktype = SOCK_STREAM;
	tmp.ai_flags = AI_PASSIVE;
	int tmp_status ;
	if((tmp_status = getaddrinfo(NULL, "0", &tmp, &local)) !=0 )
		fprintf(stderr,"Error in finding local address..!! %s\n",gai_strerror(tmp_status));


#ifdef DEBUG
//------------------------debuggin part			*/
struct addrinfo *tmp1;
char st[20];

for(tmp1 = local; tmp1 != NULL; tmp1=tmp1->ai_next)
{
void *addr;
struct sockaddr_in *ipv = (struct sockaddr_in *)tmp1->ai_addr;
addr = &(ipv->sin_addr);
inet_ntop(AF_INET, addr, st,sizeof st);
printf("%s\n",st);
}
//-----------------------debugging part ends		*/
#endif

	
	if(bind(fd, local->ai_addr, sizeof(struct sockaddr_in)) == -1)
		printf("Error in binding\n");
	else
#ifdef DEBUG
		printf("Done binding..!\n");
#endif

	host.sin_family = AF_INET;
	host.sin_port = htons( port );
	host.sin_addr = *( ( struct in_addr *)host_det->h_addr);

	if(connect(fd, (struct sockaddr *)&host, sizeof(struct sockaddr_in)) == -1)
		printf("Server is taking too long to respond..\n");
	else
#ifdef DEBUG
		printf("Connected..\n");
#endif

	return fd;
}
