/*
============================================================================
Name : 17a.c
Author : Atul Tripathi
Description : C program to open a file or create if doesnt exist, and then
assign the first ticket value to the file.
Date: 28th Aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(){
const char *filepath="tick.txt";
int fd= open(filepath,O_WRONLY|O_CREAT, 0644);
if(fd==-1){
perror("file cannot be opened");
return 1;
}
int ticket=1;
write(fd,&ticket,sizeof(int));
close(fd);
printf("ticket reservation done\n");
return 0;
}
