/*a simple downloader						*\
*								*
\*(c) 2010 pradeepkumar gayam<deepu.aprjc@gmail.com>		*/

//Main function is here
/*
  this program is free software; you can redistribute it and/or modify
  it under the terms of the gnu general public license as published by
  the free software foundation; either version 2 of the license, or
  (at your option) any later version.

  this program is distributed in the hope that it will be useful,
  but without any warranty; without even the implied warranty of
  merchantability or fitness for a particular purpose.  see the
  gnu general public license for more details.

  you should have received a copy of the gnu general public license with
  the debian gnu/linux distribution in file /usr/doc/copyright/gpl;
  if not, write to the free software foundation, inc., 59 temple place,
  suite 330, boston, ma  02111-1307  usa
*/



#include "download.h"

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("Usage: \"download url\"\n");
		exit(-1);
	}

	char url[MAXSTRING];
	remove_proto(argv[1],url);

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
