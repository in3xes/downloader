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

/*
	while(bites_read = read(fd, data, size))
	{
			if(index == 0)
			{
				char *data_first;
				data_first = strstr(data, "e\r\n");
//				printf("%s\t%i\n","came here..",strlen(data_first));
				write(file_fd, data_first, strlen(data_first));
				int asdf;
				char *data_w;
				data_w = malloc(sizeof(char));
				memset(data_w,'\0',sizeof(char));
				for(asdf = 0; asdf < strlen(data_first); asdf++)
				{
					data_w[asdf] = data_first[asdf];
				}
				printf("%s\t%i\n","came here..",strlen(data_w));

				write(file_fd, data_w,strlen(data_first)-4);
				memset(data,'\0',MAXBUFFER);

				index = 10;
			}
			else
			{
				printf("%i\n",bites_read);
				write(file_fd, data, bites_read);
				memset(data,'\0',MAXBUFFER);
			}
	}

*/
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
			printf("%s",data);
		}
	}
	
	while(bites_read = read(fd,data,1))
	{
		write(file_fd,data,bites_read);
	}	
	
	close(file_fd);
}
