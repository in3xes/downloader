/*									
(c) Pradeepkumar Gayam<deepu.aprjc@gmail.com>		*/

#include "main.h"

int tcp_connect(char *host_name, int port)
{
	struct addrinfo *local;
	struct sockaddr_in host;
	struct hostent *host_det;
	int fd;
	
	if(!(host_det = gethostbyname(host_name)))
		printf("Error in finding hostname..!!\n");
	
//	printf("Info: %i\n",*host_det->h_name);	
	
	if(fd = socket(AF_INET, SOCK_STREAM, 0))
		printf("Socket created..!\n");
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
	
	if(bind(fd, local->ai_addr, sizeof(struct sockaddr_in)) == -1)
		printf("Error in binding\n");
	else
		printf("Done binding..!\n");

	host.sin_family = AF_INET;
	host.sin_port = htons( port );
	host.sin_addr = *( ( struct in_addr *)host_det->h_addr);

	if(connect(fd, (struct sockaddr *)&host, sizeof(struct sockaddr_in)) == -1)
		printf("Error in connecting..!!\n");
	else
		printf("Connected..\n");

	return fd;
}
