/*
============================================================================
Name : 17b.c
Author : Atul Tripathi
Description : C program to implement ticket booking one by one, by taking the prev
value of ticket after locking and increamenting for ticket number and then releasing
the lock
Date: 28th Aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
const char *filepath="tick.txt";
int fd=open(filepath,O_RDWR);
   if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    struct flock lock;
    lock.l_type = F_WRLCK;  
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;       
    lock.l_len = 0;        
    lock.l_pid = getpid();  
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Error setting lock");
        close(fd);
        return 1;
    }
    int current_ticket;
    read(fd, &current_ticket, sizeof(int));
    printf("Current ticket number: %d\n", current_ticket);
    current_ticket++;
    lseek(fd, 0, SEEK_SET); 
    write(fd, &current_ticket, sizeof(int));
    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("lock not released");
    }

    // Close the file
    close(fd);

    return 0;
}

