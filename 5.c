#include<stdio.h>
#include<fcntl.h>
int main(int argc,char* argv[])
{
creat("file1",0777);
creat("file2",0777);
creat("file3",0777);
creat("file4",0777);
creat("file5",0777);
while(1)
{}

return 0;
}
