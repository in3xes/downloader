/*								*/
/*(C)Pradeepkumar Gayam<deepu.aprjc@gmail.com>			*/

#include "download.h"

void parse(char *url)
{
	char *a,*path,*filename;
	a = strrchr(url, '/');
	strcpy(filename,&a[1]);
	path = strchr(url, '/');

#ifdef DEBUG
	printf("%s\t%s\n", url,filename);
	printf("%s\t%s\n", url,path);
#endif
	
}

void host(char *url)
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

#ifdef DEBUG
	printf("%s\t%s\n",url,name);
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
