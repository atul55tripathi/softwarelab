#include <sys/types.h>
#include <sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
int main (int argc, char * argv[])
{
printf("%d",argc);
printf("%s", argv[0]);
return 0;
}
