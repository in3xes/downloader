/*								*
*(C)Pradeepkumar Gayam<deepu.aprjc@gmail.com>			*/

#include "download.h"

int main()
{
	char *host_name = "www.iitr.ac.in";
	int port = 80;	
	int fd;
	char path[MAXSTRING] = "asdf", filename[MAXSTRING]="asdfff";
	strcpy(path,"index.html");
//	printf("%s\n",path);
	strcpy(filename,"index.htmk");
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
