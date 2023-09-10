/*
============================================================================
Name : 4.c
Author : Atul Tripathi
Description : C program to open an existing file in read write mode
Date: 5th Aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>

int main()
{
int fd;
fd= open("text",O_RDWR|O_CREAT|O_EXCL,0777);
printf("output: %d\n",fd);
if(fd==-1)
printf("failed\n");
else
printf("suucess\n");
}
