/*A simple downloader						*\
*								*
\*(C) 2010 Pradeepkumar Gayam<deepu.aprjc@gmail.com>		*/

//Url manpulator
/*
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License with
  the Debian GNU/Linux distribution in file /usr/doc/copyright/GPL;
  if not, write to the Free Software Foundation, Inc., 59 Temple Place,
  Suite 330, Boston, MA  02111-1307  USA
*/


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
			path = strchr(url,'/');
			strcpy(object->path, path);

		}
		else
		{
			strcpy(object->filename,"index.html");
			path = strchr(url,'/');
			strcpy(object->path,path);
		}

	}
	else
	{
		strcpy(object->filename,"index.html");
		strcpy(object->path,"/");

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


void remove_proto(char *url,char *final_url)
{
//	char tmp[MAXSTRING];
	char *tmp;
	tmp = malloc(sizeof(char));
	memset(tmp,0,sizeof(char));
	if(!(strstr(url,"://")))
		strcpy(final_url, url);
	else if(url[0] == 'f')
	{
		printf("FTP Protocal not supported!\n");
		exit(0);
	}
	else
	{
		int ln = strlen(url);
		int dx;
		for( dx = 0; dx < ln-6; dx++)
		{
			tmp[dx] = url[dx+7];
		}
		strcpy(final_url,tmp);
	}

/*	else
	{
		printf("else");
		tmp = strstr(url,"//");
		strcpy(final_url, tmp);
	}
*/	
}

void http_status(downloader *object)
{
	char *status;
	status = malloc(sizeof(char));
	memset(status,0,sizeof(char));
	int a;
	for(a=0; a<3; a++)
	{
		status[a] = object->header[a+9];
	}
	object->status = atoi(status);
	printf("HTTP Status is %i\n", object->status);
}

void redirect(downloader *object)
{
	if(object->status >= 200 && object->status < 300)
		printf("O.K\n");
	else if(object->status >= 300 && object->status < 400)
	{
		printf("Page has been moved\n");
		char *next_url;
		next_url = strstr(object->header,"http");
		char *garbage;
		garbage = strchr(next_url,'\n');
		int gar_len = strlen(garbage);
		char asali[MAXSTRING];
		strncpy(asali,next_url, strlen(next_url)-strlen(garbage));
		asali[strlen(next_url)-strlen(garbage)]='\0';
		printf("New url is %s\n", asali);
	
	}
	else if(object->status >=400 && object->status <500)
		printf("Bad Request\n");
	else 
		printf("Server Error\n");
}
