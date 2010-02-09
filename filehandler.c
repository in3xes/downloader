/*a simple downloader						*\
*								*
\*(c) 2010 pradeepkumar gayam<deepu.aprjc@gmail.com>		*/

//downloading occurs here
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

double gettime()
{
	struct timeval time[1];
	
	gettimeofday( time, 0 );
	return( (double) time->tv_sec + (double) time->tv_usec / 1000000 );
}

void download(int fd, downloader *object)
{
	add_command(object,"GET %S HTTP/1.0", object->path);
	add_command(object,"HOST: %s",object->host);
	add_command(object,"Range: bytes=%s","1-");
	strcat(object->command, "\n");

	
#ifdef DEBUG
	printf("%s Length of command%i",object->command,strlen(object->command));
#endif

	ssize_t bites_write = write(fd, object->command, strlen(object->command));
//	printf("%i\n", bites_write);
	
	ssize_t bites_read = 0;
	size_t size = MAXBUFFER;
	char data[MAXBUFFER];
//	int file_fd = open(object->filename, O_WRONLY | O_CREAT, 0700);
	int index = 0;

	int i = 0;
	while(1)
	{
		if(bites_read = read(fd,data,1))
		{
			if(*data == '\r')
				continue;
			else if(*data == '\n')
			{
				if(i == 0)
					break;
				i=0;
			}
			else
				i++;

			printf("%s%i",data,strlen(data));
			strncat(object->header,data,1);
		}
	}

#ifdef DEBUG
	printf("Header:\n%s%i\n",object->header,strlen(object->header));
#endif

	http_status(object);
	redirect(object);


	int file_fd = open(object->filename, O_WRONLY | O_CREAT, 0700);


	int bites = 0, total_bites=0;
	double start, end,rem;
	start = gettime();
	rem = gettime();
//	printf("Time at starting is %lf\n",start);
	while(bites_read = read(fd,data,1))
	{
		write(file_fd,data,bites_read);
		if(bites > 1000)
		{
			end = gettime();
			double speed = (end - start); //CLOCKS_PER_SEC;
			int final_speed = (int )bites/(speed*1000);
			printf("Download speed: %iK/s\n",final_speed);
			start = end;
			bites = 0;
		}
		bites = bites + bites_read;
		total_bites = total_bites + bites_read;
		if((bites%20)== 0)
			printf(".");
	}
	printf("\nAverage speed : %iK/s, Size of file is %i, (%iK), %i Sce\n\n",(int)(total_bites/((end-rem)*1000)),total_bites,total_bites/1000,(int)(end-rem));


//	printf("Time elapsed is %lf\n",end-rem);

	close(file_fd);
}


