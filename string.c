/*								*/
/*(C)Pradeepkumar Gayam<deepu.aprjc@gmail.com>			*/

#include "download.h"

void parse(char *url, downloader *object)
{
	char *a,*path,filename[MAXSTRING];
	if(a = strrchr(url, '/'))
	{
		int len = strlen(a);
		if(len > 1)
		{
			int index;
			for(index = 0; index < len; index++)
			{
				filename[index] = (char )a[index+1];
			}
			filename[len] ='\0';
			strcpy(object->filename, filename);

		}
		else
		{
			strcpy(object->filename,"index.html");
			strcpy(object->path,"index.html");
		}

	}
	else
	{
		strcpy(object->filename,"index.html");
		strcpy(object->path,"/index.html");

	}
		

/*	
	if(!(object->path = strchr(url, '/')))
	{
		char buff[MAXSTRING];
		strcpy(buff,url);
		strcat(buff,"/index.html");
		object->path = strchr(buff, '/');

//		strcpy(object->path,"/index.html");
	}
	else if(!(strlen(object->path) > 1))
	{
		char buff[MAXSTRING];
		strcpy(buff,url);
		strcat(buff,"index.html");
		object->path = strchr(buff, '/');
	}
	else
	{
		object->path = strchr(url, '/');
	}
//	path = strchr(url,'/');
*/

//	object->path = strchr(buff, '/');

#ifdef DEBUG
	printf("%s\t%s\t", object->path,object->filename);
#endif	
}

void host(char *url,downloader *object)
{

	char *path;
	if(path = strchr(url, '/'))
	{
		size_t len_path = strlen(path);
		size_t len_url = strlen(url);
		size_t len = len_url - len_path;

		char name[MAXSTRING];
		strncpy(name, url, len);
		name[len]='\0';
		strcpy(object->host, name);
	}
	else
		strcpy(object->host,url);

#ifdef DEBUG
	printf("%s\n",object->host);
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
