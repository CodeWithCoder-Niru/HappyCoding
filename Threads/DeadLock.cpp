/**
 * 
 * It is situation where two or more threads are blocked forever, waiting for each other.
 * It occurs when two or more threads are waiting for each other to release a resource, and
 * none of them can proceed because they are all waiting for each other to release the resource.
 */

#include<bits/stdc++.h>

std::mutex m1, m2;

int main(){
    std::thread t1([&](){
        m1.lock();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout<<"Thread 1 acquired m1, trying to acquire m2"<<std::endl;
        m2.lock();
        m2.unlock();
        m1.unlock();
    });

    std::thread t2([&](){
        m2.lock();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout<<"Thread 2 acquired m2, trying to acquire m1"<<std::endl;
        m1.lock();
        m1.unlock();
        m2.unlock();
    });

    t1.join();
    t2.join();

    return 0;
}