/*
============================================================================
Name : 30_c.c
Author : Ankit Karwasra
Description : Write a program to create a shared memory.
                c. Detach the shared memory
Date: 25th sep, 2025.
============================================================================
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main()
{
    key_t key = ftok(".", 'a');
    int shmid = shmget(key, 1024, IPC_CREAT | 0666);

    char *data = shmat(shmid, (void *)0, 0);
    printf("Detaching\n");
    shmdt(data);

    return (0);
}

/*
root@ankit-karwasra:/handson2$ ./a.out 
Detaching
*/