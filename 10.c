/*
============================================================================
Name : 10.c
Author : Atul Tripathi
Description : C program to write 10 bytes, then use lseek to skip 10 place
and then again write 10 bytes
Date: 15th Aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int fd;
	fd = open("text.txt",O_RDWR|O_CREAT);
	if(fd == -1)
	{
		printf("Error occured!!\n");
	}
	int w;
	write(fd,"asdfghjkl;",strlen("asdfghjkl;"));
	int seek = lseek(fd,10,SEEK_CUR);
	write(fd,"qwertyuiop",strlen("qwertyuiop"));
	printf("\nPointer after lseek : %d\n",seek);
	system("od text");
	return 0;
}
