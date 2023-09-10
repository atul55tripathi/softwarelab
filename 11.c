/*
============================================================================
Name : 11.c
Author : Atul Tripathi
Description : duplicate the file descriptor using dup, dup2 and fcntl
Date: 19th Aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main()
{
	int fd;
	fd = open("temp.txt",O_RDWR|O_APPEND);
	if(fd == -1)
	printf("Error not there\n");
	
	write(fd,"from original fd\n",strlen("from original fd\n"));
	int fcntl_dup = fcntl(fd,F_DUPFD);
	write(fcntl,"printing from duplicate fd\n",strlen("printing from duplicate fd\n"));
	return 0;
}
