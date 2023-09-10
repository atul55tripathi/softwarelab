/*
============================================================================
Name : 28.c
Author : Atul Tripathi
Description : C program to find maximum and minimum real time priority of program
Date: 3rd Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sched.h>

int main()
{
  int min_priority,max_priority;
  
  
  min_priority = sched_get_priority_min(SCHED_RR);
  
  printf("Minimum Priority Is : %d \n",min_priority);
  
  max_priority=sched_get_priority_max(SCHED_RR);
  
  printf("Maximum Priority Is : %d \n",max_priority);
  
  return 0;

}

