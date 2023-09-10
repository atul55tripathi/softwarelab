/*
============================================================================
Name : 25.c
Author : Atul Tripathi
Description : C program to create orphan process
Date: 2nd Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int i;
    pid_t cp[3];
    int status;

    for (i = 0; i < 3; i++) {
        cp[i] = fork();

        if (cp[i] == -1) {
            perror("fork() failed");
            exit(1);
        }

        if (cp[i] == 0) {
    
            printf("Child %d (PID %d) is running.\n", i+1, getpid());
            sleep(2);
            exit(0);
        }
    }

    printf("Parent (PID %d) is waiting for Child 2 (PID %d).\n", getpid(), cp[1]);

    pid_t terminated_pid = waitpid(cp[1], &status, 0);

    if (terminated_pid == -1) {
        perror("waitpid() failed");
        exit(1);
    }

    if (WIFEXITED(status)) {
        printf("Child %d (PID %d) exited with status %d.\n", 2, terminated_pid, WEXITSTATUS(status));
    }

    printf("Parent (PID %d) continues.\n", getpid());

    return 0;
}
