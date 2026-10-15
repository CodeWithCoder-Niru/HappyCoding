
 
#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
 
std::condition_variable cv;
 
bool ex1 = false;
bool ex2 = false;
 
void generateRandomNumer(int &value, std::mutex &mtx) {
    while(1) {
        srand(time(NULL));
        value = (rand() % 100);
        ex1 = true;
        ex2 = true;
        cv.notify_all();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void printEven(int &value, std::mutex &mtx) {
    while(1) {
        std::unique_lock<std::mutex> ul(mtx);
        cv.wait(ul, [&]() {
            return ((value & 1) ? false : true) && ex1;
        });
        ex1 = false;
        std::cout<<"Even Thread id : "<<std::this_thread::get_id()<<" value = "<<value<<std::endl;
    }
}
 
void printOdd(int &value, std::mutex &mtx) {
    while(1) {
        std::unique_lock<std::mutex> ul(mtx);
        cv.wait(ul, [&]() {
            return ((value & 1) ? true : false) && ex2;
        });
        ex2 = false;
        std::cout<<"Odd Thread id : "<<std::this_thread::get_id()<<" value = "<<value<<std::endl;
    }
}
 
int main() {
    int value = 0;
    std::mutex mtx;
    std::thread t1(generateRandomNumer, std::ref(value), std::ref(mtx));
    std::thread t2(printEven, std::ref(value), std::ref(mtx));
    std::thread t3(printOdd, std::ref(value), std::ref(mtx));
    t1.join();
    t2.join();
    t3.join();
}
 
 