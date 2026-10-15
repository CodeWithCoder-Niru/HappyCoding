/*
    Conditional Variable in C++
    A conditional variable is a synchronization primitive that allows threads to wait for certain conditions to be met before proceeding with their execution.
    It is typically used in conjunction with a mutex to protect shared data and coordinate  the execution of threads based on specific conditions.

    Notes:
    1) Notify other threads that are waiting on the condition variable using notify_one() or notify_all() member functions.
    2) Wait for a condition to be met using wait() member function, which releases the associated mutex and blocks the thread until the condition is notified.
    3) you need mutex to use condition variable
    4) If some thread want to wait  on some condition then it has to do these things:
        a) acquire the lock using std::unique_lock<std::mutex> (or std::lock_guard<std::mutex>) to protect the shared data associated with the condition variable.
        b) Execute wait, wait_for, or wait_until. the wait operation atomaically release the mutex and suspend the execution of the thread
        c) then the cv will be notified, the thread will be awakedned . and the mutex is atomatically reacquired before the wait function returns.
           the thread should then check the condition and resume waiting if the wake up was spurious or the condition is not satisfied.
    5) Spurious wakeups can occur, where a thread may wake up without being 
*/

#include <bits/stdc++.h>

std::mutex mtx; // Mutex to protect shared data
std::condition_variable cv; // Condition variable for synchronizatiion

int balance = 2000; // Shared data

void addMoney(int money = 0) {
    while (balance != 0) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::lock_guard<std::mutex> lock(mtx);
        balance = balance+money;
        std::cout <<"Amount added to current balance: " << balance <<std::endl;
        cv.notify_one();
    }
}

void withdrowMoney(int withMoney) {
    while(balance != 0) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{
            return (balance != 0)? true: false;
        });

        if(balance >= withMoney) {
            balance = balance - withMoney;
            std::cout <<"Amount deducted: " <<withMoney << std::endl;
        }
        else {
            std::cout <<"Amount can not be deducted , current balance is less" << std::endl;
        }
    }
}




int main() {

    std::thread t1(addMoney, 2000);
    std::thread t2(withdrowMoney, 200);
    t1.join();
    t2.join();  
    return 0;
}



