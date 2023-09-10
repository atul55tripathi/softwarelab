/*
============================================================================
Name : 15.c
Author : Atul Tripathi
Description : program to display environment variables. 
Date: 21st Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>

extern char** environ;

int main() {
    char** env = environ;

    while (*env) {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}
