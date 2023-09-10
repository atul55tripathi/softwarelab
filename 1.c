/*
============================================================================
Name : 1.c
Author : Atul Tripathi
Description : C program to make hard link, soft link and a namespipe.
Date: 5th Aug, 2023.
============================================================================
*/
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
	int v= symlink("test","soft");
	if(v<0)
	{
	perror("failed ");return 1;}
	int f= link("test","hard");
	if(f<0)
	{
	perror("failed");return 1;}
	int e= mknod("pipeFIFO",S_IFIFO,0);
	if(e<0)
	perror("failed");
	return 0;
	}
