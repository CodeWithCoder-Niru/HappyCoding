#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <string>

int main()
{
    const char* fifoPath = "/tmp/myfifo";

    std::cout << "Opening FIFO...\n";

    int fd = open(fifoPath, O_WRONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    std::string message = "Hello from Writer";

    write(
        fd,
        message.c_str(),
        message.size()
    );

    std::cout << "Message sent\n";

    close(fd);

    return 0;
}