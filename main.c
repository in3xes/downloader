/*								*
*(C)Pradeepkumar Gayam<deepu.aprjc@gmail.com>			*/

#include "download.h"

int main(int argc, char *argv[])
//int main()
{
	if(argc < 2)
	{
		printf("Usage: \"download url\"\n");
		exit(-1);
	}

	
	char *url = argv[1];
//	char *url = "www.google.com/";
	downloader *obj ;
	obj = malloc( sizeof( downloader ) );
	memset(obj,0,sizeof(downloader));

	int port = 80;	
	int fd;


/*---------------------------------------------------*\
	char path[MAXSTRING], filename[MAXSTRING];
	strcpy(path,"/index.html");
	printf("%s\n",path);
	strcpy(filename,"index.html"); 
\*---------------------------------------------------*/

	parse(url, obj);
	host(url,obj);

#ifdef DEBUG
	printf("%i\t%s\t%s\t%s\n",strlen(obj->path),obj->filename,obj->path,obj->host);
#endif

	if(fd = tcp_connect(obj , port))
	{
#ifdef DEBUG
		printf("it's working..!!\n");
#endif
	}

	download(fd, obj);
	
#ifdef DEBUG
	printf("Debug enabled\n");
#endif
	return 0;
}
