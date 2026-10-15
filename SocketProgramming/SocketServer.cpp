/**
 * 
 */

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include<bits/stdc++.h>


int main() {

    //Intialise the socket
    int nSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(nSocket < 0) {
        std::cout<< "The socket not opened"<<std::endl;
    } else {
        std::cout<< "The socket opened succesfully" << nSocket <<std::endl;
    }
    //Initialise the Environment for socket structure
    struct sockaddr_in serverAddress;

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    std::memset(&(serverAddress.sin_zero), '\0', 8);

    //bind the socket to local port
    if(bind(nSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        std::cout << "Bind failed" << std::endl;
        close(nSocket);
        return -1;
    }

    //listen the request from client (queues the requests)
    if(listen(nSocket, 5) < 0) {
        std::cout << "Listen failed" << std::endl;
        close(nSocket);
        return -1;
    }

    std::cout << "Server is listening on port 8080" << std::endl;

    //keep waiting for new request and proceed as per the request
    struct sockaddr_in clientAddress;
    socklen_t clientLen = sizeof(clientAddress);
    int clientSocket = accept(nSocket, (struct sockaddr*)&clientAddress, &clientLen);
    if(clientSocket < 0) {
        std::cout << "Accept failed" << std::endl;
        close(nSocket);
        return -1;
    }

    std::cout << "Client connected!" << std::endl;

    // Receive message from client
    char buffer[1024] = {0};
    int bytesRead = read(clientSocket, buffer, sizeof(buffer) - 1);
    if(bytesRead > 0) {
        std::cout << "Client says: " << buffer << std::endl;
    }

    // Send response to client
    const char* response = "Hello from server!";
    send(clientSocket, response, strlen(response), 0);

    close(clientSocket);
    close(nSocket);

    return 0;
}