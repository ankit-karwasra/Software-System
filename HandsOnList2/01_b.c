/*
============================================================================
Name : 01_b.c
Author : Ankit Karwasra
Description :   Write a separate program (for each time domain) to set a interval timer in 10s and 10ms
                b. ITIMER_VIRTUAL
Date: 20th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void handler()
{
    printf("Signal received\n");
}

int main()
{
    struct itimerval it;
    signal(SIGVTALRM, handler);

    
    it.it_value.tv_sec = 10;
    it.it_value.tv_usec = 10;

    
    it.it_interval.tv_sec = 10;
    it.it_interval.tv_usec = 10;

    setitimer(ITIMER_VIRTUAL, &it, NULL);

    while (1){}
}

/*

Signal received
Signal received
Signal received
*/

