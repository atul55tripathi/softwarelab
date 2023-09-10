/*
============================================================================
Name : 29.c
Author : Atul Tripathi
Description : C program to get scheduling policy and modify the policy
Date: 3rd Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

int main() {
    int pid = getpid(); 
    int current_policy = sched_getscheduler(pid);
    if (current_policy == -1) {
        perror("could not run get scheduler");
        return 0;
    }
    printf("for pid- %d the scheduling policy is: ", pid);
    switch (current_policy) {
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;
        default:
            printf("Unknown (%d)\n", current_policy);
            break;
    }
    struct sched_param param;
    param.sched_priority = 1; 

    int set_policy_result = sched_setscheduler(pid, SCHED_FIFO, &param);
    if (set_policy_result == -1) {
        perror("unable to set schedule");
	return 0;;
    }

    int new_policy = sched_getscheduler(pid);
    if (new_policy == -1) {
        perror("unable to get shceduler");
        return -1;
    }
    printf("the new scheduling policy is pid =  %d: ", pid);
    switch (new_policy) {
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;
        default:
            printf("Unknown (%d)\n", new_policy);
            break;
    }
return 0;
}
