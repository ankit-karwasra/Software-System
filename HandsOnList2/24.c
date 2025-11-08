/*
============================================================================
Name : 24.c
Author : Ankit Karwasra
Description : Write a program to create a message queue and print the key and message queue id.
Date: 23rd sep, 2025.
============================================================================
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

// Create a message queue.
int main()
{
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, IPC_CREAT | 0666);
    printf("Key: %d, ID: %d\n", key, msqid);
    return(0);
}

/*
root@ankit-karwasra:/handson2$ ./a.out 
Key: 1627521236, ID: 0
*/