/*								*
*(C)Pradeepkumar Gayam<deepu.aprjc@gmail.com>			*/

#include "download.h"

int main()
{
	char *url = "www.iitr.ac.in/path/to/folder/index.html";
	downloader *obj ;
	obj = malloc( sizeof( downloader ) );
	memset(obj,0,sizeof(downloader));

	int port = 80;	
	int fd;


//---------------------------------------------------
/*	char path[MAXSTRING], filename[MAXSTRING];
	strcpy(path,"/index.html");
//	printf("%s\n",path);
	strcpy(filename,"index.html"); */
//---------------------------------------------------

	parse(url, obj);
	host(url,obj);
//	printf("%s\t%s\t%s\n",obj->filename,obj->path,obj->host);

	if(fd = tcp_connect(obj->host, port))
	{
#ifdef DEBUG
		printf("it's working..!!\n");
#endif
	}

//	download(fd, path, filename);
	
#ifdef DEBUG
	printf("Debug enabled\n");
#endif
	return 0;
}
