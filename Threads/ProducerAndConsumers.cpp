/**
 * THE PROBLEM STATEMENT:
 1. Producer will produce and consumer will consume with synchronisation of a common buffer.
 2. Until producer thread produces any data consumer thread can't consume.
 3. Threads will use condition_variable to notify each other.
 4. We need mutex if we use condition_variable because CV waits on mutex.
 5. This is one of the example of producer consumer there are many.

PRODUCER thread steps:
 1. lock mutex, if success then go ahead otherwise wait for mutex to get free.
 2. check if buffer is full and if it is full then unlock mutex and sleep, if not then go ahead and produce.
 3. insert item in buffer.
 4. unlock mutex. 
 5. notify consumer.

CONSUMER thread steps:
 1. lock mutex, if success then go ahead otherwise wait for mutex to get free.
 2. check if buffer is empty and if it is, then unlock the mutex and sleep, if not then go ahead and consume.
 3. consume item from buffer.
 4. unlock mutex.
 5. notify producer.

 IMP:
 Producer and Consumer have to notify each other upon completion of their job.
 */

// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

std::mutex mx;
std::condition_variable cv;
std::queue<int> myqueue;
constexpr int MAX_BUFFER_SIZE = 10;
bool production_done = false;

void producer(int value) {
    while(value > 0){
        std::unique_lock<std::mutex> lock(mx);
        cv.wait(lock, [&](){
            return myqueue.size() < MAX_BUFFER_SIZE;
        });
        std::cout<< "Inserting Value into Queue:" <<value <<std::endl;
        myqueue.push(value);
        --value;
        cv.notify_one();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::lock_guard<std::mutex> lock(mx);
    production_done = true;
    cv.notify_one();
} 

void consumer(){
    while(true){
        std::unique_lock<std::mutex> lock(mx);
        cv.wait(lock, [](){
            return !myqueue.empty() || production_done;
        });
        if(myqueue.empty() && production_done)
            break;
        std::cout<< "Removing Value from Queue:" <<myqueue.front() <<std::endl;
        myqueue.pop();
        cv.notify_one();
    }
}


int main() {
    std::thread t1(producer, 11);
    std::thread t2(consumer);
    t1.join();
    t2.join();

    return 0;
};