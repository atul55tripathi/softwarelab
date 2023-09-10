/*
============================================================================
Name : 6.c
Author : Atul Tripathi
Description : C program to read and write using stdin and stdout
Date: 11th Aug, 2023.
============================================================================
*/

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main(int argc,char* argv[])
{
char red[20];
printf("enter the string\n");
read(0,red,20);
printf("\nstored in buffer\nprinting buffer\n");
write(1,red,20);
printf("\nprinting the stored string:\n");
printf("%s",red);

return 0;
}

