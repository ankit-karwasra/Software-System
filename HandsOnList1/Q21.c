/*
============================================================================
Name : Q21.c
Author : Ankit Karwasra
Description :Write a program, call fork and print the parent and child process id.
Date: 31th Aug, 2025.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
int main()
{
    printf("Id of parent process is = %d\n", getpid());
    int a = fork();
    if(a) printf("Id of child process is = %d\n", a);
    return 0;
}
/*
Id of parent process is = 80756
Id of child process is = 80757
*/
