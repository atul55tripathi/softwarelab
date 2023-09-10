/*
============================================================================
Name : 30.c
Author : Atul Tripathi
Description : C program to run a script at a specific time by daemon process.
Date: 3rd Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

void run_script() {
    char* script_path = "/home/atul/shellprac/1.sh";
    
    if (execv(script_path, NULL) == -1) {
        perror("execv");
        exit(EXIT_FAILURE);
    }
}

int main() {
    pid_t child_pid;
    int desired_hour = 12; 
    int desired_minute = 17;  

    while (1) {
        time_t current_time = time(NULL);
        struct tm* timeinfo = localtime(&current_time);

        if (timeinfo->tm_hour == desired_hour && timeinfo->tm_min == desired_minute) {
            child_pid = fork();

            if (child_pid == -1) {
                perror("fork");
                exit(EXIT_FAILURE);
            } else if (child_pid == 0) {
                run_script();
            } else {

                int status;
                waitpid(child_pid, &status, 0);
                if (WIFEXITED(status)) {
                    printf("Script exited with status %d\n", WEXITSTATUS(status));
                }
                exit(EXIT_SUCCESS);
            }
        }
        sleep(60);
    }

    return 0;
}
