/*
Trylock = Try to Lock
A trylock is a non-blocking version of a mutex lock.
It attempts to acquire the lock without blocking the thread.
If the lock is already held by another thread, trylock returns immediately with a failure status.
Why Do We Need Trylock?
In some scenarios, you may want to attempt to acquire a lock without blocking the thread.
For example, if you want to perform some work only if the lock is available, you can use trylock to check if the lock can be acquired without waiting.
This can help improve performance and responsiveness in certain situations, especially when the lock is not critical and can be skipped if it's already held by another thread.

//if try_lock() is called by again by the same thread that already holds the lock, it will cause a deadlock.
// In this case, the thread will be waiting for itself to release the lock, which will never happen, resulting in a deadlock situation.
 */

#include <bits/stdc++.h>


std::mutex mtx; // Mutex to protect shared data
int counter = 0; // Shared data
void increment() {
    for (int i = 0; i < 9; i++) {
        if(mtx.try_lock()) { // Try to lock the mutex without blocking
            counter++;   // Critical section: modifying shared data 
            mtx.unlock(); // Unlock the mutex after accessing the critical section
        } else {
            // Lock is already held by another thread, skip this iteration
            std::this_thread::yield(); // Yield to allow other threads to run
        }
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