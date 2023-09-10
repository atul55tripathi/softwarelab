/*
============================================================================
Name : 16b.c
Author : Atul Tripathi
Description : C program to implement read lock and releasing the lock on 
taking ENTER as input
Date: 21st Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char* filename = "lockcheck.txt";
    int fd;

    fd = open(filename, O_RDONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    struct flock fl;
    fl.l_type = F_RDLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0;  

    if (fcntl(fd, F_SETLKW, &fl) == -1) {
        perror("Error setting read lock");
        return 1;
    }
    printf("read lock activated. press enter to release.\n");
    getchar();
    fl.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLKW, &fl) == -1) {
        perror("Error releasing lock");
        return 1;
    }

    close(fd);

    return 0;
}
