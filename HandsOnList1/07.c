/*
============================================================================
Name : 07.c
Author : Ankit karwasra
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 25th Aug, 2025.
============================================================================
*/

#include <sys/types.h>	
#include <sys/stat.h>	
#include <fcntl.h>	
#include <unistd.h>	
#include <stdio.h>	

int main(int argc, char *argv[]){
	if(argc < 3){
		perror("Source and Destination File to be entered\n");
		return 0;
	}
	char *buffer[100];
	int readByte;
	int writeByte;

	int sourceFD = open(argv[1],O_RDONLY);
	int destinationFD = -1;
	if(sourceFD != -1) destinationFD = open(argv[2], O_CREAT | O_RDWR, S_IRWXU);

	if(destinationFD == -1){
		perror("Error in source / destination File \n");
		return 0;
	}

	while((readByte = read(sourceFD,buffer,1024)) > 0){
		writeByte = write(destinationFD, buffer, readByte);
		if(writeByte == -1){
			perror("Error in writing into file\n");
			return 0;
		}
	}
	if(readByte == -1){
		perror("Error in reading from source file\n");
	}else{
		printf("Successfully copied the file contents\n");
	}

	close(sourceFD);
	close(destinationFD);
	return 0;
}
/*
./a.out 01_a.c test.txt
Successfully copied the file contents
cat test.txt 
*/