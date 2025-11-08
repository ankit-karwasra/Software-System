/*
============================================================================
Name : 29.c
Author : Ankit Karwasra
Description : Write a program to remove the message queue.
Date: 25th sep, 2025.
============================================================================
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

// Remove a message queue.
int main()
{
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, 0);

    (msgctl(msqid, IPC_RMID, NULL) == -1) ? printf("Delete unsuccessful\n") : printf("Delete successful\n");
    
    return (0);
}

/*
root@ankit-karwasra:/handson2$ ./a.out 
Delete successful
*/