/*
============================================================================
Name : 06.c
Author : Ankit Karwasra
Description :  Write a simple program to create three threads.
Date: 20th Sep, 2025.
============================================================================
*/

#include <pthread.h>
#include <stdio.h>

void show_thread(void)
{
    printf("This is a thread\n");
}

int main()
{
    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, (void *)show_thread, NULL);
    pthread_create(&t2, NULL, (void *)show_thread, NULL);
    pthread_create(&t3, NULL, (void *)show_thread, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    return 0;
}

/*
root@ankit-karwasra:/handson2$ ./a.out 
This is a thread
This is a thread
This is a thread
*/