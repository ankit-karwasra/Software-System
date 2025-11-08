/*
============================================================================
Name : 32_a.c
Author : Ankit Karwasra
Description : Write a program to implement semaphore to protect any critical section.
                a. Rewrite the ticket number creation program using semaphore
                b. Protect shared memory from concurrent write access
                c. Protect multiple pseudo resources (may be two) using counting semaphore
                d. Remove the created semaphore
Date: 25th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>

#define SHM_SIZE 1024

union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main()
{

    
    int shm_key = ftok(".", 'S');
    int sem_key = ftok(".", 'T');

    
    int shm_id = shmget(shm_key, 1024, IPC_CREAT | 0666);
    int sem_id = semget(sem_key, 1, IPC_CREAT | 0666);

    
    union semun sem_args;
    sem_args.val = 1;
    if (semctl(sem_id, 0, SETVAL, sem_args) == -1)
    {
        printf("Error in semctl system call\n");
        return -1;
    }

    
    int *shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *)-1)
    {
        
        printf("Error in shmat call\n");
        return -1;
    }

    
    *shm_ptr = 0;
}