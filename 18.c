/*
============================================================================
Name : 18.c
Author : Atul Tripathi
Description : c program to perform record locking and perform write and retrieve
operations by accessing and releasing lock
Date: 28th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

struct Record {
    int id;
    char data[256];
};

void acquireWriteLock(int fd, int recordNum) {
    struct flock write_pointer;
    write_pointer.l_type = F_WRLCK;
    write_pointer.l_whence = SEEK_SET;
    write_pointer.l_start = recordNum * sizeof(struct Record);
    write_pointer.l_len = sizeof(struct Record);
    write_pointer.l_pid = getpid();

    if (fcntl(fd, F_SETLKW, &write_pointer) == -1) {
        printf("Error acquiring write lock\n");
	exit(EXIT_FAILURE);
    }
}

void acquireReadLock(int fd, int recordNum) {
    struct flock read_pointer;
    read_pointer.l_type = F_RDLCK;
    read_pointer.l_whence = SEEK_SET;
    read_pointer.l_start = recordNum * sizeof(struct Record);
    read_pointer.l_len = sizeof(struct Record);
    read_pointer.l_pid = getpid();

    if (fcntl(fd, F_SETLKW, &read_pointer) == -1) {
        printf("Error Acquiring Read Lock\n");
	exit(EXIT_FAILURE);
    }
}

void releaseLock(int fd, int recordNum) {
    struct flock fl;
    fl.l_type = F_UNLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = recordNum * sizeof(struct Record);
    fl.l_len = sizeof(struct Record);
    fl.l_pid = getpid();

    if (fcntl(fd, F_SETLK, &fl) == -1) {
        printf("Error releasing lock\n");
	exit(EXIT_FAILURE);
    }
}

int main() {
    int fd = open("data_records.txt", O_RDWR | O_CREAT,0666);
    if (fd == -1) {
        printf("Error opening file, Please try Again\n");
	exit(EXIT_FAILURE);
    }
    struct Record records[3];
    for (int i = 0; i < 3; ++i) {
        records[i].id = i + 1;
        printf("Enter the data for Records[%d]\n", i + 1);
        gets(records[i].data);
        write(fd, &records[i], sizeof(struct Record));
    }
    while (1) { // Now We Reading and Writing on the Same Records 
    printf("Do You want to Read or Write the Record. Enter 1 for Write on the record or 0 for Read on the record or 2 for break the file\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
	 int recordNum;
	 printf("Enter the Record Num to Write\n");
	 scanf("%d", &recordNum);
	 acquireWriteLock(fd, recordNum);
	 printf("Write lock acquired for record %d. Modifying record...\n", recordNum);
	 lseek(fd, recordNum * sizeof(struct Record), SEEK_SET);
	 read(fd, &records[recordNum], sizeof(struct Record));
	 printf("Enter the data for Records[%d]\n", recordNum);
	 if (getchar())	 gets(records[recordNum].data);
	 lseek(fd, recordNum * sizeof(struct Record), SEEK_SET);
	 write(fd, &records[recordNum], sizeof(struct Record));
	 printf("Record modified.\n");
	 releaseLock(fd, recordNum);
    }
    if (choice == 0) {
	 int recordNum;
	 printf("Enter the Record Num to Read\n");
	 scanf("%d", &recordNum);
	 acquireReadLock(fd, recordNum);
	 printf("Read lock acquired for record %d. Accessing record...\n", recordNum);
	 lseek(fd, recordNum * sizeof(struct Record), SEEK_SET);
	 read(fd, &records[recordNum], sizeof(struct Record));
         printf("Record %d: ID = %d, Data = %s\n", recordNum, records[recordNum].id, records[recordNum].data);
	 releaseLock(fd, recordNum);
    }
    if (choice == 2) break;
    }
    close(fd); 
    return 0;
}
