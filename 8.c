/*
============================================================================
Name : 8.c
Author : Atul Tripathi
Description : C program to read line by line and display as each line is read.
Date: 11th Aug, 2023.
============================================================================
*/
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
int main(int argc, char* argv[])
{
	if(argc!=2)
	{
	printf("less arguments entered\n");
	return -1;
	}
	int fdr=open(argv[1], O_RDONLY);
	
	if(fdr==-1)
	{printf("not able to read\n");
	
	}
	char line[70];
	int i=0;
	while(1)
	{
	
	char buf;
	int read_byte=read(fdr,&buf,1);
	line[i++]=buf;
	if(read_byte==0)
	break;
	
	if(line[i-1]=='\n')
	{write(1,line,i);
		i=0;
	}
	}
	if(close(fdr)!=0)
	{
	printf("the file not closed");
	}
	
	return 0;
	}
	
