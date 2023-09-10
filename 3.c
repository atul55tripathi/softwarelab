/*
============================================================================
Name : 3.c
Author : Atul Tripathi
Description : C program to creat a file and print the file descriptor value
Date: 5th Aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
int main()
{
int fd;
fd= creat("temp3.txt",0777);
printf("file descriptor value : %d\n",fd);
return 0;
}
