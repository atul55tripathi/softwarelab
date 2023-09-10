/*
============================================================================
Name : 21.c
Author : Atul Tripathi
Description : C program to print parent and child process id using fork.
Date: 1st Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
if(fork())
{
printf("the parent pid is %d\n",getpid());
}
else
{
printf("the child pid is %d\n",getpid());
}

return 0;
}
