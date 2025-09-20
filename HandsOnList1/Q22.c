/*
============================================================================
Name : Q22.c
Author : Ankit Karwasra
Description :Write a program, open a file, call fork, and then write to the file by both the child as well as the
             parent processes. Check output of the file.
Date: 31th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    int fd;
    pid_t pid;
    const char* filename = "q22_output.txt";

    printf("--- Setup: Creating and opening '%s' for writing ---\n", filename);
    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (fd == -1) {
        perror("Setup failed");
        exit(EXIT_FAILURE);
    }
    printf("--- Setup complete. File descriptor is %d ---\n\n", fd);

    printf("--- Calling fork() to create a child process ---\n");
    pid = fork();

    if (pid == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        printf("--> Child Process: Writing my message to the file.\n");
        const char* child_message = "This message was written by the CHILD.\n";
        write(fd, child_message, strlen(child_message));
        close(fd);
        printf("--> Child Process: Finished.\n");
        exit(EXIT_SUCCESS);
    } else {
        printf("--> Parent Process: Writing my message to the file.\n");
        const char* parent_message = "This message was written by the PARENT.\n";
        write(fd, parent_message, strlen(parent_message));
        close(fd);
        printf("--> Parent Process: Waiting for child to finish.\n");
        wait(NULL);
        printf("--> Parent Process: Finished.\n");
    }

    printf("\n--- Program finished. Check the contents of '%s' ---\n", filename);

    return 0;
}
/*
Output:
--- Setup: Creating and opening 'q22_output.txt' for writing ---
--- Setup complete. File descriptor is 3 ---

--- Calling fork() to create a child process ---
--> Parent Process: Writing my message to the file.
--> Child Process: Writing my message to the file.
--> Parent Process: Waiting for child to finish.
--> Child Process: Finished.
--> Parent Process: Finished.

--- Program finished. Check the contents of 'q22_output.txt' ---
root@ankit-karwasra:/handson1/15# cat q22_output.txt
This message was written by the PARENT.
This message was written by the CHILD.
*/
