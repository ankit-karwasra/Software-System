/*
============================================================================
Name : Q29.c
Author : Ankit Karwasra
Description :Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
             SCHED_RR).
Date: 1st Sep, 2025.
============================================================================
*/
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
  int pid = getpid();
  int curr_policy;
  struct sched_param parameter;
  curr_policy = sched_getscheduler(pid);
  
  switch(curr_policy) {
     case SCHED_OTHER:
        printf("Current scheduling policy is SCHED_OTHER\n");
        break;
     case SCHED_FIFO:
        printf("Current scheduling policy is SCHED_FIFO\n");
        break;
     case SCHED_RR:
        printf("Current scheduling policy is SCHED_RR\n");
        break;
      default:
        printf("Unknown scheduling policy\n");
        break;
    }
    printf("Setting new scheduling policy...\n");

    parameter.sched_priority = 1;
    sched_setscheduler(pid, SCHED_FIFO, &parameter);
    curr_policy = sched_getscheduler(pid);
    
  switch(curr_policy) {
     case SCHED_OTHER:
        printf("Current scheduling policy is SCHED_OTHER\n");
        break;
     case SCHED_FIFO:
        printf("Current scheduling policy is SCHED_FIFO\n");
        break;
     case SCHED_RR:
        printf("Current scheduling policy is SCHED_RR\n");
        break;
      default:
        printf("Unknown scheduling policy\n");
        break;
    }
    
    printf("Switching to SCHED_RR...\n");

    parameter.sched_priority = 1;  
    sched_setscheduler(pid, SCHED_RR, &parameter);
    curr_policy = sched_getscheduler(pid);

  switch(curr_policy) {
     case SCHED_OTHER:
        printf("Current scheduling policy is SCHED_OTHER\n");
        break;
     case SCHED_FIFO:
        printf("Current scheduling policy is SCHED_FIFO\n");
        break;
     case SCHED_RR:
        printf("Current scheduling policy is SCHED_RR\n");
        break;
      default:
        printf("Unknown scheduling policy\n");
        break;
    }

  return 0;
}
/*
Output:
root@ankit-karwasra:/handson1# touch 29.c
root@ankit-karwasra:/handson1# vim 29.c
root@ankit-karwasra:/handson1# gcc 29.c -o 29
root@ankit-karwasra:/handson1# ./29
Current scheduling policy is SCHED_OTHER
Setting new scheduling policy...
Current scheduling policy is SCHED_OTHER
Switching to SCHED_RR...
Current scheduling policy is SCHED_OTHER

*/
