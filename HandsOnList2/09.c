/*
============================================================================
Name : 09.c
Author : Ankit Karwasra
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - Use signal system call.
Date: 20th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(){
    printf("Ignoring SIGINT signal\n");
    signal(SIGINT, SIG_IGN);
    sleep(7);
    printf("\nDefault action of SIGINT signal\n");
    signal(SIGINT, SIG_DFL);
    sleep(7);
    return(0);
}

/*

Ignoring SIGINT signal
^C^C^C^C^C^C
Default action of SIGINT signal

root@ankit-karwasra:/handson2$ ./a.out 
Ignoring SIGINT signal

Default action of SIGINT signal
^C
*/