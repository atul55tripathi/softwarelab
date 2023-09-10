/*
============================================================================
Name : 20.c
Author : Atul Tripathi
Description : C program to change nice value of program
Date: 1st Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int nice_value;
    
    // Get the current nice value of the process
    nice_value = nice(0);
    if (nice_value == -1) {
        perror("Error getting nice value");
        return 1;
    }

    printf("Current nice value: %d\nnow changing the nice value to +5\n", nice_value);
    

    // Increase the priority of the process using nice
    if (nice(-3) == -1) {  // You can adjust the nice value here
        perror("Error setting nice value");
        return 1;
    }

    printf("Increased priority using nice.\n");
    
    printf("the current nice value of program is %d\n",nice(0));
    
 

    return 0;
}
