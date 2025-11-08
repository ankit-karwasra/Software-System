/*
============================================================================
Name : 34_b.c
Author : Ankit Karwasra
Description : Write a program to create a concurrent server.
                a. Use fork
                b. Use pthread_create
Date: 25th sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 5555
#define BUFFER_SIZE 1024

void *handle_client(void *socket_desc) {
    int nsfd = *(int *)socket_desc;
    free(socket_desc);  

    char buffer[BUFFER_SIZE] = {0};
    int read_size;

    
    while ((read_size = read(nsfd, buffer, sizeof(buffer))) > 0) {
        printf("Received from client: %s\n", buffer);

        
        const char *message = "Message From server\n";
        write(nsfd, message, strlen(message));

        memset(buffer, 0, BUFFER_SIZE);  
    }

    if (read_size == 0) {
        printf("Client disconnected.\n");
    } else if (read_size < 0) {
        perror("Read failed");
    }

    
    close(nsfd);
    return NULL;
}

int main() {
    struct sockaddr_in server, client;
    int sd, nsd, clientLen;

    
    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;  
    server.sin_port = htons(PORT);

    
    if (bind(sd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Bind failed");
        close(sd);
        exit(EXIT_FAILURE);
    }

    
    if (listen(sd, 5) < 0) {
        perror("Listen failed");
        close(sd);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (true) {
        clientLen = sizeof(client);
        nsd = accept(sd, (struct sockaddr *)&client, (socklen_t *)&clientLen);
        if (nsd < 0) {
            perror("Accept failed");
            continue; // Skip this iteration if accept fails
        }

        printf("Connected to client from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        // Allocate memory for the socket descriptor to pass to thread
        int *new_sock = malloc(sizeof(int));
        if (new_sock == NULL) {
            perror("Could not allocate memory");
            close(nsd);
            continue;
        }
        *new_sock = nsd;

        // Create a new thread for the connection
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)new_sock) != 0) {
            perror("Could not create thread");
            free(new_sock); // Free memory if thread creation fails
            close(nsd);
        }
        pthread_detach(thread_id); // Detach the thread to handle its cleanup automatically
    }

    
    close(sd);
    return 0;
}

/*
root@ankit-karwasra:/handson2$ ./a.out 
Server is listening on port 5555
Connected to client from 127.0.0.1:40786
Received from client: Hello from client
Client disconnected.
*/