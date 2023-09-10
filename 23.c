/*
============================================================================
Name : 23.c
Author : Atul Tripathi
Description : C program to create zombie process by making the parent sleep
for 19sec
Date: 1st Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
pid_t c;
c=fork();
if(c<0)
{
perror("fork failed");
exit(1);
}
if(c==0)
{
printf("child process is exiting\n");
exit(0);
}
else{
sleep(19);
printf("parent process is exiting\n");
}
return 0;
}
