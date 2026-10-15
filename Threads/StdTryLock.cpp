/*
Few things to remember about the try_lock is as follows:
0. std::try_lock() tries to lock all the mutex passed in it one by one in given order.
1. On success this function returns -1 otherwise it will return 0-based mutex index number which it could not lock.
2. If it fails to lock any of the mutex then it will release all the mutex it locked before.
3. If a call to try_lock results in an exception, unlock is called for any locked objects before re-throwing.
*/

#include<bits/stdc++.h>
#include<thread>
#include<mutex>
#include <chrono>

std::mutex m1, m2;
int X=0, Y=0;;

void increamentXY(int &xy, std::mutex& m, const char* desc) {
    for(int i=0; i<5; ++i) {
        m.lock();
            ++xy;
        std::cout<<desc << xy <<std::endl;
        m.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
}

void consumeXY() {
    int cont =5;
    int sumXY = 0;
    while(true) {
        int lockResult = std::try_lock(m1,m2);
        if((lockResult == -1) && (X!=0) && (Y!=0)) {
            --cont;
            sumXY+=X+Y;
            X=0;
            Y=0;
            std::cout<<std::endl<<"Sum of XY :"<< sumXY << std::endl;
        }
        m1.unlock();
        m2.unlock();
        if(cont == 0) {
            break;
        }
    }
}

int main() {
    std::thread t1(increamentXY, std::ref(X), std::ref(m1), "X: ");
    std::thread t2(increamentXY, std::ref(Y), std::ref(m2), "Y: ");
    std::thread t3(consumeXY);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}