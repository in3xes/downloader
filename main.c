/*								*
*(C)Pradeepkumar Gayam<deepu.aprjc@gmail.com>			*/

#include "download.h"

int main()
{
	char *host_name = "www.iitr.ac.in";
	char *url = "www.iitr.ac.in/path/to/folder/index.html";
//	char *host_name = "wilmer.gaast.net";

	int port = 80;	
	int fd;
/*	char path[MAXSTRING], filename[MAXSTRING];
	strcpy(path,"/index.html");
//	printf("%s\n",path);
	strcpy(filename,"index.html"); */
	if(fd = tcp_connect(host_name, port))
	{
#ifdef DEBUG
		printf("it's working..!!\n");
#endif
	}
	
//	download(fd, path, filename);
	
	parse(url);
	host(url);
	if(1)
	{
#ifdef DEBUG
	printf("Debug enabled\n");
#endif
	}
	return 0;
}	
