/*
============================================================================
Name : 12.c
Author : Atul Tripathi
Description : C program to know the opening mode of the file using fcntl
Date: 19th Aug, 2023.
============================================================================
*/
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<stdio.h>
int main(){
	int fd=open("text",O_RDONLY);
	int flags,accessMode;
	flags=fcntl(fd,F_GETFL);
	if(flags==-1)
		exit(1);
	printf("opening mode %d \n",flags);
}
