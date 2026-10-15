/*
Mutex = Mutual Exclusion
A mutex is a synchronization primitive used to protect shared data from being accessed by multiple threads at the same time.
It ensures: Only one thread can access a critical section at a time.

Why Do We Need a Mutex?
Because threads share memory.
When multiple threads modify the same variable simultaneously, you get race conditions.
A mutex allows you to lock a critical section of code, ensuring that only one thread can execute it at a time.
*/

#include <bits/stdc++.h>

std::mutex mtx;

int counter = 0;

void increment() {
    for (int i = 0; i < 100000; ++i) {
        mtx.lock(); // Lock the mutex before accessing the critical section
        ++counter;   // Critical section: modifying shared data
        mtx.unlock(); // Unlock the mutex after accessing the critical section
    }
}

int main() {

    std::thread t1(increment);
    std::thread t2(increment);
    t1.join();
    t2.join();

    std::cout << "Final counter value: " << counter << std::endl; // Output the final value of the counter
    return 0;
}