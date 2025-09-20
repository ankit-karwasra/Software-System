/*
============================================================================
Name : 08.c
Author : Ankit Karwasra
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read. Close the file when end of file is reached.
Date: 25th Aug, 2025.
============================================================================
*/

#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>     
#include <unistd.h>    
#include <stdio.h>     

int main(int argc, char *argv[]){
	if(argc <= 1){
		perror("Please enter File Name\n");
		return 0;
	}

	int sourceFD = open(argv[1],O_RDONLY);

	char *buffer;

	int readByte;
	int writeByte;
	
	while((readByte = read(sourceFD,buffer, 1)) > 0 ){
		if(buffer[0] == '\n') getchar();
		writeByte = write(STDOUT_FILENO,buffer,readByte);
		if(writeByte == -1){
			perror("Error while printing\n");
			return 0;
		}
	}
	if(readByte == -1){
		perror("Error in reading from File\n");
	}
	return 0;
}



