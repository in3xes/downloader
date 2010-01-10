/*								*
*(C)Pradeepkumar Gayam<deepu.aprjc@gmail.com>			*/

#include "download.h"

int main()
{
//	char *host_name = "www.iitr.ac.in";
	char *host_name = "wilmer.gaast.net";

	int port = 80;	
	int fd;
	char path[MAXSTRING], filename[MAXSTRING];
	strcpy(path,"downloads/axel-1.0b.tar.gz");
//	printf("%s\n",path);
	strcpy(filename,"axel-1.0b.tar.gz");
	if(fd = tcp_connect(host_name, port))
#ifdef DEBUG
		printf("it's working..!!\n");
#endif
	
	download(fd, path, filename);
	
	if(1)
#ifdef DEBUG
	printf("Debug defined\n");
#endif
	return 0;
}	
