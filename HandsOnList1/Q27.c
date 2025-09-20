/*
============================================================================
Name : Q27.c
Author : Ankit Karwasra
Description :Write a program to execute ls -Rl by the following system calls
             a. execl
             b. execlp
             c. execle
             d. execv
             e. execvp
Date: 7th Sep, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

int main() {
    pid_t pid;

    printf("\n--- 1. Testing execl (using full path /bin/ls) ---\n");
    pid = fork();
    if (pid == 0) {
        execl("/bin/ls", "ls", "-Rl", NULL);
        perror("execl failed");
        exit(1);
    }
    wait(NULL);

    printf("\n--- 2. Testing execlp (searching PATH for ls) ---\n");
    pid = fork();
    if (pid == 0) {
        execlp("ls", "ls", "-Rl", NULL);
        perror("execlp failed");
        exit(1);
    }
    wait(NULL);

    printf("\n--- 3. Testing execle (with environment variables) ---\n");
    pid = fork();
    if (pid == 0) {
        execle("/bin/ls", "ls", "-Rl", NULL, environ);
        perror("execle failed");
        exit(1);
    }
    wait(NULL);

    printf("\n--- 4. Testing execv (using an argument array) ---\n");
    char *argv_v[] = {"ls", "-Rl", NULL};
    pid = fork();
    if (pid == 0) {
        execv("/bin/ls", argv_v);
        perror("execv failed");
        exit(1);
    }
    wait(NULL);

    printf("\n--- 5. Testing execvp (searching PATH and using array) ---\n");
    char *argv_vp[] = {"ls", "-Rl", NULL};
    pid = fork();
    if (pid == 0) {
        execvp("ls", argv_vp);
        perror("execvp failed");
        exit(1);
    }
    wait(NULL);

    printf("\n--- All five exec tests are complete. ---\n");
    return 0;
}

/*
Output:
--- 1. Testing execl (using full path /bin/ls) ---
.:
total 52
drwxr-xr-x 2 root root  4096 Sep  7 18:13 15
-rwxr-xr-x 1 root root 70504 Sep  7 18:26 26
-rw-r--r-- 1 root root   472 Sep  7 18:16 26.c
-rwxr-xr-x 1 root root 70904 Sep  7 18:39 27
-rw-r--r-- 1 root root  1418 Sep  7 18:39 27.c
-rw-r--r-- 1 root root    73 Sep  7 18:17 file1.txt

./15:
total 68
-rwxr-xr-x 1 root root 70416 Sep  7 18:09 26
-rw-r--r-- 1 root root   138 Sep  7 18:08 26.c
-rw-r--r-- 1 root root    41 Sep  7 18:11 file1.txt
-rwxr-xr-x 1 root root 70688 Sep  7 17:58 fork_write
-rw-r--r-- 1 root root  1496 Sep  7 17:58 fork_write.c
-rw-r--r-- 1 root root    79 Sep  7 18:04 q22_output.txt
-rwxr-xr-x 1 root root 70424 Sep  7 17:37 test
-rw-r--r-- 1 root root   593 Sep  7 17:34 test15.c

--- 2. Testing execlp (searching PATH for ls) ---
.:
total 52
drwxr-xr-x 2 root root  4096 Sep  7 18:13 15
-rwxr-xr-x 1 root root 70504 Sep  7 18:26 26
-rw-r--r-- 1 root root   472 Sep  7 18:16 26.c
-rwxr-xr-x 1 root root 70904 Sep  7 18:39 27
-rw-r--r-- 1 root root  1418 Sep  7 18:39 27.c
-rw-r--r-- 1 root root    73 Sep  7 18:17 file1.txt

./15:
total 68
-rwxr-xr-x 1 root root 70416 Sep  7 18:09 26
-rw-r--r-- 1 root root   138 Sep  7 18:08 26.c
-rw-r--r-- 1 root root    41 Sep  7 18:11 file1.txt
-rwxr-xr-x 1 root root 70688 Sep  7 17:58 fork_write
-rw-r--r-- 1 root root  1496 Sep  7 17:58 fork_write.c
-rw-r--r-- 1 root root    79 Sep  7 18:04 q22_output.txt
-rwxr-xr-x 1 root root 70424 Sep  7 17:37 test
-rw-r--r-- 1 root root   593 Sep  7 17:34 test15.c

--- 3. Testing execle (with environment variables) ---
.:
total 52
drwxr-xr-x 2 root root  4096 Sep  7 18:13 15
-rwxr-xr-x 1 root root 70504 Sep  7 18:26 26
-rw-r--r-- 1 root root   472 Sep  7 18:16 26.c
-rwxr-xr-x 1 root root 70904 Sep  7 18:39 27
-rw-r--r-- 1 root root  1418 Sep  7 18:39 27.c
-rw-r--r-- 1 root root    73 Sep  7 18:17 file1.txt

./15:
total 68
-rwxr-xr-x 1 root root 70416 Sep  7 18:09 26
-rw-r--r-- 1 root root   138 Sep  7 18:08 26.c
-rw-r--r-- 1 root root    41 Sep  7 18:11 file1.txt
-rwxr-xr-x 1 root root 70688 Sep  7 17:58 fork_write
-rw-r--r-- 1 root root  1496 Sep  7 17:58 fork_write.c
-rw-r--r-- 1 root root    79 Sep  7 18:04 q22_output.txt
-rwxr-xr-x 1 root root 70424 Sep  7 17:37 test
-rw-r--r-- 1 root root   593 Sep  7 17:34 test15.c

--- 4. Testing execv (using an argument array) ---
.:
total 52
drwxr-xr-x 2 root root  4096 Sep  7 18:13 15
-rwxr-xr-x 1 root root 70504 Sep  7 18:26 26
-rw-r--r-- 1 root root   472 Sep  7 18:16 26.c
-rwxr-xr-x 1 root root 70904 Sep  7 18:39 27
-rw-r--r-- 1 root root  1418 Sep  7 18:39 27.c
-rw-r--r-- 1 root root    73 Sep  7 18:17 file1.txt

./15:
total 68
-rwxr-xr-x 1 root root 70416 Sep  7 18:09 26
-rw-r--r-- 1 root root   138 Sep  7 18:08 26.c
-rw-r--r-- 1 root root    41 Sep  7 18:11 file1.txt
-rwxr-xr-x 1 root root 70688 Sep  7 17:58 fork_write
-rw-r--r-- 1 root root  1496 Sep  7 17:58 fork_write.c
-rw-r--r-- 1 root root    79 Sep  7 18:04 q22_output.txt
-rwxr-xr-x 1 root root 70424 Sep  7 17:37 test
-rw-r--r-- 1 root root   593 Sep  7 17:34 test15.c

--- 5. Testing execvp (searching PATH and using array) ---
.:
total 52
drwxr-xr-x 2 root root  4096 Sep  7 18:13 15
-rwxr-xr-x 1 root root 70504 Sep  7 18:26 26
-rw-r--r-- 1 root root   472 Sep  7 18:16 26.c
-rwxr-xr-x 1 root root 70904 Sep  7 18:39 27
-rw-r--r-- 1 root root  1418 Sep  7 18:39 27.c
-rw-r--r-- 1 root root    73 Sep  7 18:17 file1.txt

./15:
total 68
-rwxr-xr-x 1 root root 70416 Sep  7 18:09 26
-rw-r--r-- 1 root root   138 Sep  7 18:08 26.c
-rw-r--r-- 1 root root    41 Sep  7 18:11 file1.txt
-rwxr-xr-x 1 root root 70688 Sep  7 17:58 fork_write
-rw-r--r-- 1 root root  1496 Sep  7 17:58 fork_write.c
-rw-r--r-- 1 root root    79 Sep  7 18:04 q22_output.txt
-rwxr-xr-x 1 root root 70424 Sep  7 17:37 test
-rw-r--r-- 1 root root   593 Sep  7 17:34 test15.c

--- All five exec tests are complete. ---
*/
