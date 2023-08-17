#include<stdio.h>
#include<fcntl.h>

int main()
{
int fd;
fd= open("text",O_CREAT|O_EXCL,0777);
printf("output: %d\n",fd);
if(fd==-1)
printf("failed\n");
else
printf("suucess\n");
}
