/*								*
*(C)Pradeepkumar Gayam<deepu.aprjc@gmail.com>			*/

#include "main.h"

int main()
{
	char *host_name = "www.google.com";
	int port = 80;	
	if(tcp_connect(host_name, port))
		printf("it's working..!!\n");
	
	return 0;
}	
