/*
============================================================================
Name : 11.c
Author : Ankit Karwasra
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - use sigaction system call.
Date: 23rd sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <bits/sigaction.h>

int main(){
    struct sigaction act;
    
    memset(&act,0,sizeof(act));
    act.sa_handler = SIG_IGN;
    printf("Ignoring SIGINT\n");
    sigaction(SIGINT,&act,NULL);
    sleep(7);
    
    memset(&act,0,sizeof(act));
    act.sa_handler = SIG_DFL;
    printf("\nDefault of SIGINT\n");
    sigaction(SIGINT,&act,NULL);
    sleep(7);
    
    return(0);
}

/*
root@ankit-karwasra:/handson2$ ./a.out 
Ignoring SIGINT

Default of SIGINT
root@ankit-karwasra:/handson2$ ./a.out 
Ignoring SIGINT
^C^C^C
Default of SIGINT
^C
*/