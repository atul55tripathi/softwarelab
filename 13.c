/*
============================================================================
Name : 13.c
Author : Atul Tripathi
Description : C program to use select command and wait for input for 10 sec 
Date: 21st Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    fd_set read_fds;
    struct timeval timeout;
    int ret;
    timeout.tv_sec = 10;    
    timeout.tv_usec = 0;

    FD_ZERO(&read_fds);    
    FD_SET(STDIN_FILENO, &read_fds); 

   

    printf("Waiting for input from STDIN for 10 seconds...\n");

    ret = select(STDIN_FILENO + 1, &read_fds, NULL, NULL, &timeout);

    if (ret == -1) {
        perror("select");
    } else if (ret == 0) {
        printf("No data available within 10 seconds.\n");
    } else {
        if (FD_ISSET(STDIN_FILENO, &read_fds)) {
            printf("Data is available within 10 seconds.\n");
            char buffer[256];
            fgets(buffer, sizeof(buffer), stdin);
        } else {
            printf("STDIN is not set.\n");
        }
    }

    return 0;
}
