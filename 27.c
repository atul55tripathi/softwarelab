/*
============================================================================
Name : 27.c
Author : Atul Tripathi
Description : C program to do ls -RL by various system calls like exexl, execlp
execle, execv and execvp
Date: 2nd Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *ls_command = "/bin/ls";
    char *ls_args[] = {"ls", "-Rl", NULL};

    // Using execl
/*    printf("Using execl:\n");
    if (execl(ls_command, ls_command, "-Rl", NULL) == -1) {
        perror("execl");
        exit(EXIT_FAILURE);
    }

    // Using execlp
    printf("\nUsing execlp:\n");
    if (execlp("ls", "ls", "-Rl", NULL) == -1) {
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    // Using execle
    printf("\nUsing execle:\n");
    if (execle(ls_command, ls_command, "-Rl", NULL, NULL) == -1) {
        perror("execle");
        exit(EXIT_FAILURE);
    }
*/
    // Using execv
    printf("\nUsing execv:\n");
    if (execv(ls_command, ls_args) == -1) {
        perror("execv");
        exit(EXIT_FAILURE);
    }

    // Using execvp
    printf("\nUsing execvp:\n");
    if (execvp("ls", ls_args) == -1) {
        perror("execvp");
        exit(EXIT_FAILURE);
    }

    return 0;
}
