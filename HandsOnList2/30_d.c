/*
============================================================================
Name : 30_d.c
Author : Ankit Karwasra
Description : Write a program to create a shared memory.
                d. Remove the shared memory
Date: 25th Sep, 2025.
============================================================================
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main()
{
    key_t key = ftok(".", 'a');
    int shmid = shmget(key, 1024, 0);

    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        printf("Delete unsuccessful\n");
    }
    else
    {
        printf("Delete successful\n");
    }

    return (0);
}

/*
root@ankit-karwasra:/handson2$ ./a.out 
Delete successful
root@ankit-karwasra:/handson2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages 

*/