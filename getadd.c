/*							*/
/*(c)Pradeepkumar Gayam<deepu.aprjc@gmail.com>		*/

#include "main.h"

int main(int argc, char *argv[])
{
	int status;
	struct addrinfo hints;
	struct addrinfo *info;

	memset(&hints, 0, sizeof(hints));
	
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags =  AI_PASSIVE;
	
	if((status = getaddrinfo(argv[1], NULL, &hints, &info)) != 0)
	{
		printf("Error%s",stderr);
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

