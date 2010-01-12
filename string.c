/*								*/
/*(C)Pradeepkumar Gayam<deepu.aprjc@gmail.com>			*/

#include "download.h"

void parse(char *url, downloader *object)
{
	char *a,*path,filename[MAXSTRING];
	a = strrchr(url, '/');
//	strcpy(filename,&a[1]);
	int index;
	int len = strlen(a);
	for(index = 0; index < len; index++)
	{
		filename[index] = (char )a[index+1];
	}
	filename[len] ='\0';
	object->path = strchr(url, '/');
	path = strchr(url,'/');
	strcpy(object->filename, filename);

#ifdef DEBUG
	printf("%s\t%s\t", path,(char *)filename);
#endif	
}

void host(char *url,downloader *object)
{

	char *path;
	char *faltu;
	path = strchr(url, '/');

	size_t len_path = strlen(path);
	size_t len_url = strlen(url);
	size_t len = len_url - len_path;

	char name[MAXSTRING];
	strncpy(name, url, len);
	name[len]='\0';
	
	strcpy(object->host, name);

#ifdef DEBUG
	printf("%s\n",name);
#endif

/*Debug								*/
/*
	char af[] = "asdf1234";
	size_t ff = 4;
	char bf[ff] ;
	strncpy(bf,af,ff);
	bf[ff]='\0';
	printf("%s\t%s\n",af,bf);
*/
/*Debug ends							*/
}
