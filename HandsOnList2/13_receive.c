/*
============================================================================
Name : 13.c
Author : Ankit Karwasra
Description : Two programs: first program is waiting to catch SIGSTOP signal, the second program
              will send the signal (using kill system call). Find out whether the first program is able to catch
              the signal or not. (First).
Date: 23rd sep, 2025.
============================================================================
*/

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <bits/sigaction.h>

void catch (int sig)
{
    printf("Signal Caught - %d\n", sig);
    exit(0);
}

int main()
{
    printf("pid (reciever): %d\n", getpid());

    struct sigaction ac;
    memset(&ac, 0, sizeof(ac));
    
    ac.sa_handler = catch;
    for (;;)
    {
        sigaction(SIGSTOP, &ac, NULL);
    }
    return (0);
}

/*
root@ankit-karwasra:/handson2$ ./13_r 
pid (reciever): 6573

[1]+  Stopped                 ./13_r
*/