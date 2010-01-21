/*A simple downloader						*\
*								*
\*(C) 2010 Pradeepkumar Gayam<deepu.aprjc@gmail.com>		*/

//A simple IP Address finder
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

int main(int argc, char *argv[])
//int main()
{
	int status;
	struct addrinfo hints;
	struct addrinfo *info;

	memset(&hints, 0, sizeof(hints));
	
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags =  AI_PASSIVE;
	
	if((status = getaddrinfo(argv[1], NULL, &hints, &info)) != 0)
//	if((status = getaddrinfo(NULL, "0", &hints, &info)) != 0)
	{
		fprintf(stderr,"Error%s",gai_strerror(status));
	}
	
	char answer[20];
	struct addrinfo *tmp;
//	tmp = info;
//	while(tmp != NULL)
	for(tmp = info; tmp != NULL; tmp=tmp->ai_next)
	{
		void *addr;
		struct sockaddr_in *result = (struct sockaddr_in *)tmp->ai_addr;
		addr = &(result->sin_addr);
		inet_ntop(tmp->ai_family, addr, answer, sizeof (answer));
		printf("IP Address is %s\n", answer);
//		info = info->ai_next;
			
	}
	
	freeaddrinfo(info);
	
	return 0;
}

