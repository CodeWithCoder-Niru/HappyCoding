#include<iostream>
#include<thread>

int main() {
    int64_t NoOfWorkerThread = std::thread::hardware_concurrency();
    std::cout<<"No of worker threads can create:"<<NoOfWorkerThread;
    return 0;
}