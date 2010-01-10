/*								*
*(C)Pradeepkumar Gayam<deepu.aprjc@gmail.com>			*/

#include "main.h"

void download(int fd, char path, char filename)
{
	char *command = "GET /";
	strcat(command, &path);
	write(fd, command, MAXSTRING);
}
