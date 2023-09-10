/*
============================================================================
Name : 24.c
Author : Atul Tripathi
Description : C program to create orphan process
Date: 2nd Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>
int main()
{
	int pid;
	pid=fork();
	if(pid)
	{
	        printf("INSIDE PARENT \n");
		printf("Parent ID is : %d\n",getpid());
		sleep(1);
		printf("Parent terminates\n");

	}
	else
	{
	        printf("INSIDE CHILD\n");
	        printf("Child Id : %d \n",getpid()); 
	        printf("My Parent Id Id : %d \n",getppid());
	        sleep(2);
		printf("New Parent Id : %d\n",getppid());
		

	}
    return 0;
}

