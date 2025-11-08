/*
============================================================================
Name : 19.c
Author : Ankit Karwasra
Description : Create a FIFO file by
                i. mknod command
                ii. mkfifo command
                iii. Use strace command to find out, which command (mknod or mkfifo) is better.
                iv. mknod system call
                v. mkfifo library function
Date: 21st sep, 2025.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

int main()
{
    char name[40];
    printf("Enter the name of fifo file: ");
    scanf("%s", name);

    int choice;
    printf("Choose an option:\n1.) mknod system call\n2.) mkfifo system call\n=> ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Using mknod system call...\n");

        if (mknod(name, __S_IFIFO | 0744, 0) == -1)
        {
            perror("Error: ");
            return -1;
        }
        printf("FIFO file created using mknod\n");
        break;
    case 2:
        printf("Using mkfifo system call...\n");

        if (mkfifo(name, 0744) == -1)
        {
            perror("Error: ");
            return -1;
        }
        printf("FIFO file created using mkfifo\n");
        break;

    default:
        printf("Invalid choice\n");
        break;
    }

    return (0);
}

/*
root@ankit-karwasra:/handson2$ ./a.out 
Enter the name of fifo file: FIFO
Choose an option:
1.) mknod system call
2.) mkfifo system call
=> 1
Using mknod system call...
FIFO file created using mknod
root@ankit-karwasra:/handson2$ ls -l
total 124
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra  861 Sep 21 18:44 01_a.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra  861 Sep 21 19:04 01_b.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra  851 Sep 21 19:06 01_c.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra 3136 Sep 21 19:08 02.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra  935 Sep 21 19:09 03.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra  360 Sep 21 19:13 04.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra 1446 Sep 21 19:31 05.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra  442 Sep 21 19:32 06.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra  749 Sep 21 19:35 07.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra 2732 Sep 21 19:37 08.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra  701 Sep 21 19:40 09.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra 1279 Sep 21 19:43 10.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra  838 Sep 21 19:47 11.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra  765 Sep 21 19:48 12.c
-rwxrwxr-x 1 ankit-karwasra ankit-karwasra 9128 Sep 21 19:55 13_r
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra 1024 Sep 21 19:55 13_r.c
-rwxrwxr-x 1 ankit-karwasra ankit-karwasra 9112 Sep 21 19:56 13_s
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra  815 Sep 21 19:56 13_s.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra  864 Sep 21 20:00 14.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra  827 Sep 21 21:10 15.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra 1036 Sep 21 21:11 16.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra 1513 Sep 21 21:13 17.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra 1318 Sep 21 21:15 18.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra 1439 Sep 21 21:17 19.c
-rwxrwxr-x 1 ankit-karwasra ankit-karwasra 9192 Sep 21 21:17 a.out
prwxr--r-- 1 ankit-karwasra ankit-karwasra    0 Sep 21 21:17 FIFO
root@ankit-karwasra:/handson2$ ./a.out 
Enter the name of fifo file: FIFO2
Choose an option:
1.) mknod system call
2.) mkfifo system call
=> 2
Using mkfifo system call...
FIFO file created using mkfifo
root@ankit-karwasra:/handson2$ ls -l
total 124
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra  861 Sep 21 18:44 01_a.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra  861 Sep 21 19:04 01_b.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra  851 Sep 21 19:06 01_c.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra 3136 Sep 21 19:08 02.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra  935 Sep 21 19:09 03.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra  360 Sep 21 19:13 04.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra 1446 Sep 21 19:31 05.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra  442 Sep 21 19:32 06.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra  749 Sep 21 19:35 07.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra 2732 Sep 21 19:37 08.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra  701 Sep 21 19:40 09.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra 1279 Sep 21 19:43 10.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra  838 Sep 21 19:47 11.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra  765 Sep 21 19:48 12.c
-rwxrwxr-x 1 ankit-karwasra ankit-karwasra 9128 Sep 21 19:55 13_r
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra 1024 Sep 21 19:55 13_r.c
-rwxrwxr-x 1 ankit-karwasra ankit-karwasra 9112 Sep 21 19:56 13_s
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra  815 Sep 21 19:56 13_s.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra  864 Sep 21 20:00 14.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra  827 Sep 21 21:10 15.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra 1036 Sep 21 21:11 16.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra 1513 Sep 21 21:13 17.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra 1318 Sep 21 21:15 18.c
-rw-rw-r-- 1 ankit-karwasra ankit-karwasra 1439 Sep 21 21:17 19.c
-rwxrwxr-x 1 ankit-karwasra ankit-karwasra 9192 Sep 21 21:17 a.out
prwxr--r-- 1 ankit-karwasra ankit-karwasra    0 Sep 21 21:17 FIFO
prwxr--r-- 1 ankit-karwasra ankit-karwasra    0 Sep 21 21:18 FIFO2
*/