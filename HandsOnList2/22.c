/*
============================================================================
Name : 22.c
Author : Ankit Karwasra
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.
Date: 23rd sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/time.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>


int main() {
    fd_set rfds;
    struct timeval tv;
    int fd;

    tv.tv_sec = 10;

    fd = open("FIFO", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    FD_ZERO(&rfds);
    FD_SET(fd, &rfds);

    if (!select(fd + 1, &rfds, NULL, NULL, &tv)) {
        printf("No data available\n");
    }
	
else{

    char buffer[100];
    
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));

    if (bytesRead == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    close(fd);
    
    printf("Data read from FIFO: %s\n", buffer);


}
    close(fd);

    return 0;
}
/*
root@ankit-karwasra:/handson2$ ./reader 
Data read from FIFO: HELLO
*/