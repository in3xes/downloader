/*								*
*(C)Pradeepkumar Gayam<deepu.aprjc@gmail.com>			*/

#include "main.h"

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
		printf("it's working..!!\n");
	
	download(fd, path, filename);
	return 0;
}	
