// Reader program for PIPE using FIFO (named pipe)

#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>


using namespace std;

int main(){

    const char* fifoPath = "/tmp/myfifo";

    mkfifo(fifoPath, 0666);
    std::cout << "Waiting for writer ..."<<std::endl;

    int fd = open(fifoPath, O_RDONLY);

    if(fd == -1){
        perror("open");
        return 1;
    }

    char buffer[200] = {};

    size_t bytesRead = read(fd, buffer, sizeof(buffer) -1);
    if (bytesRead > 0)
    {
        buffer[bytesRead] = '\0';

        std::cout
            << "Reader received: "
            << buffer
            << '\n';
    }
    close(fd);
    unlink(fifoPath);
    return 0;

}