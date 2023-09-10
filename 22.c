/*
============================================================================
Name : 22.c
Author : Atul Tripathi
Description : C program to create a file and write using both parent and child
process in the file.
Date: 2nd Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{

  char buff1[20]="hello Parent ";
  char buff2[20]="hello child";
  int fd=open("test.txt",O_RDWR);
  if(fork())
  {
    write(fd,&buff1,sizeof(buff1));
  }
  else
  {
    write(fd,&buff2,sizeof(buff2));
  }

}
