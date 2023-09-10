/*
============================================================================
Name : 9.c
Author : Atul Tripathi
Description : C program to print stat information about a file.
Date: 15th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

int main(int argc,char* argv[]) {
    const char *file_path = "your_file_path_here";
    
    int fd = open(argv[1], O_RDONLY);
    if (fd != -1) {
        struct stat file_stat;
    if (fstat(fd, &file_stat) == 0) {
        printf("Inode: %lu\n", (unsigned long)file_stat.st_ino);
        printf("Number of hard links: %lu\n", (unsigned long)file_stat.st_nlink);
        printf("UID: %u\n", file_stat.st_uid);
        printf("GID: %u\n", file_stat.st_gid);
        printf("Size: %ld bytes\n", (long)file_stat.st_size);
        printf("Block size: %ld bytes\n", (long)file_stat.st_blksize);
        printf("Number of blocks: %ld\n", (long)file_stat.st_blocks);
        printf("Time of last access: %s", ctime(&file_stat.st_atime));
        printf("Time of last modification: %s", ctime(&file_stat.st_mtime));
        printf("Time of last change: %s", ctime(&file_stat.st_ctime));
    } else {
        printf("File information not available.\n");
    }
        close(fd);
    } else {
        printf("File not found.\n");
    }
    
    return 0;
}

