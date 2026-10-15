

#include<bits/stdc++.h>
#include <sys/wait.h>

int main(){

    int fd[2];
    int sd[2];

    pipe(fd); //create the two file descriptor fd[0]--> read, fd[1]-->write
    pipe(sd);

    pid_t id = fork(); // create the new child process

    if(id == 0){
        //Child Process
        close(fd[1]); //to avoid the dead lock scenario like always waiting for write
        close(sd[0]);

        char buffer[20] = {};

        read(fd[0], buffer, sizeof(buffer));

        std::cout<< "Child Process :" << buffer <<std::endl;

        std::string result{"Child: Received the Message"};

        write(sd[1], result.c_str(), sizeof(result));

        close(fd[0]);
        close(sd[1]);
    }else{
        //Parent Process
        close(fd[0]);
        close(sd[1]);

        std::string message = "Hello world";

        write(fd[1], message.c_str(), sizeof(message));
        
        wait(nullptr);

        char buf[100] = {};

        read(sd[0], buf, sizeof(buf));
        std::cout<< "Parent Process :" << buf <<std::endl;

        close(fd[1]);
        close(sd[0]);
        // wait(nullptr); //wait for child process complete
    }
}