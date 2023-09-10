/*
============================================================================
Name : 14.c
Author : Atul Tripathi
Description : C program to take input as filename and then identify
the type of file it is.
Date: 21st Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    const char *file_path = argv[1];
    struct stat file_info;

    if (lstat(file_path, &file_info) == -1) {
        perror("Error");
        return 1;
    }

    if (S_ISREG(file_info.st_mode)) {
        printf("Regular File\n");
    } else if (S_ISDIR(file_info.st_mode)) {
        printf("Directory\n");
    } else if (S_ISLNK(file_info.st_mode)) {
        printf("Symbolic Link\n");
    } else if (S_ISCHR(file_info.st_mode)) {
        printf("Character Device\n");
    } else if (S_ISBLK(file_info.st_mode)) {
        printf("Block Device\n");
    } else if (S_ISFIFO(file_info.st_mode)) {
        printf("FIFO (Named Pipe)\n");
    } else {
        printf("Unknown\n");
    }

    return 0;
}
