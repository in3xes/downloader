/*								*
*(C)Pradeepkumar Gayam<deepu.aprjc@gmail.com>			*/

#include "download.h"

void download(int fd, downloader *object)
{
	char command[MAXSTRING];
	strcpy(command ,"GET ");
	strcat(command, object->path);
	printf("%s\n",object->path);
	strcat(command, " HTTP/1.0\nHost: ");
	strcat(command, object->host);
	strcat(command, "\n\n");
	printf("%s",command);
	ssize_t bites_write = write(fd, command, MAXSTRING);
//	printf("%i\n", bites_write);
	
	ssize_t bites_read = 0;
	size_t size = MAXBUFFER;
	char data[MAXBUFFER];
	int file_fd = open(object->filename, O_WRONLY | O_CREAT, 0700);
	int index = 0;
	while(bites_read = read(fd, data, size))
	{
//			printf("%s\n",data);
			printf("%i\n",bites_read);
			write(file_fd, data, bites_read);
			memset(data,'\0',MAXBUFFER);
	}
	
	close(file_fd);
}
