/**
 * Socket Client - connects to the server on 127.0.0.1:8080
 */

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int main() {

    // Create socket
    int nSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(nSocket < 0) {
        std::cout << "Socket creation failed" << std::endl;
        return -1;
    }
    std::cout << "Socket created successfully" << std::endl;

    // Set up server address to connect to
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if(connect(nSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        std::cout << "Connection failed" << std::endl;
        close(nSocket);
        return -1;
    }
    std::cout << "Connected to server!" << std::endl;

    // Send message to server
    const char* message = "Hello from client!";
    send(nSocket, message, strlen(message), 0);

    // Receive response from server
    char buffer[1024] = {0};
    int bytesRead = read(nSocket, buffer, sizeof(buffer) - 1);
    if(bytesRead > 0) {
        std::cout << "Server says: " << buffer << std::endl;
    }

    close(nSocket);
    return 0;
}
