/*								*
*(C)Pradeepkumar Gayam<deepu.aprjc@gmail.com>			*/

#include "download.h"

void download(int fd, char *path, char *filename)
{
	char command[MAXSTRING];
	strcpy(command ,"GET /");
	strcat(command, path);
	strcat(command, " HTTP/1.0\n");
	strcat(command, "Host: www.iitr.ac.in\n\n");
	printf("%s",command);
	ssize_t bites_write = write(fd, command, MAXSTRING);
//	printf("%i\n", bites_write);
	
	ssize_t bites_read = 0;
	size_t size = MAXBUFFER;
	char data[MAXBUFFER];
	while(bites_read = read(fd, data, size))
	{
//			printf("%s\n",data);
			printf("%i\n",bites_read);
			memset(data,'\0',MAXBUFFER);
	}
}
