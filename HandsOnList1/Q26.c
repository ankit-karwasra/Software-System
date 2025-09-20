/*
============================================================================
Name : Q26.c
Author : Ankit Karwasra
Description :Write a program to execute an executable program.
             a. use some executable program
             b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 1st Sep, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    
    char* arg[] = {"cat", "file1.txt", NULL};

    
    execv("/bin/cat", arg);

    
    perror("execv failed");
    return 1;
}
/*
Output:
file 1

Hello from Bengaluru! This file is being displayed by the 'cat' command.
*/
