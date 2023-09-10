/*
============================================================================
Name : 16a.c
Author : Atul Tripathi
Description : C program to implement write lock, and in the critical section
releasing the lock on input as Enter.
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

    fd = open(filename, O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    struct flock fl;
    fl.l_type = F_WRLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0;  

    if (fcntl(fd, F_SETLKW, &fl) == -1) {
        perror("Error setting write lock");
        return 1;
    }
    printf("write lock activated. press enter to release.\n");
    getchar();
    fl.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLKW, &fl) == -1) {
        perror("Error releasing lock");
        return 1;
    }

    close(fd);

    return 0;
}
