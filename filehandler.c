/*								*
*(C)Pradeepkumar Gayam<deepu.aprjc@gmail.com>			*/

#include "download.h"

double gettime()
{
	struct timeval time[1];
	
	gettimeofday( time, 0 );
	return( (double) time->tv_sec + (double) time->tv_usec / 1000000 );
}

void download(int fd, downloader *object)
{
	char command[MAXSTRING];
	strcpy(command ,"GET ");
	strcat(command, object->path);
	strcat(command, " HTTP/1.0\nHost: ");
	strcat(command, object->host);
	strcat(command, "\n\n");

#ifdef DEBUG
	printf("%s",command);
#endif

	ssize_t bites_write = write(fd, command, MAXSTRING);
//	printf("%i\n", bites_write);
	
	ssize_t bites_read = 0;
	size_t size = MAXBUFFER;
	char data[MAXBUFFER];
	int file_fd = open(object->filename, O_WRONLY | O_CREAT, 0700);
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

//			printf("%s",data);
			strcat(object->header,data);
		}
	}
	
	int bites = 0, total_bites=0;
	double start, end,rem;
	start = gettime();
	rem = gettime();
//	printf("Time at starting is %lf\n",start);
	while(bites_read = read(fd,data,1))
	{
		write(file_fd,data,bites_read);
		if(bites > 10000)
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
		if((bites%200)== 0)
			printf(".");
	}
	printf("\nAverage speed : %iK/s, Size of file is %i, (%iK), %i Sce\n\n",(int)(total_bites/((end-rem)*1000)),total_bites,total_bites/1000,(int)(end-rem));

#ifdef DEBUG
	printf("Header:\n%s\n",object->header);
#endif

//	printf("Time elapsed is %lf\n",end-rem);

	close(file_fd);
}


