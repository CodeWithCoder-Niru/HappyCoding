/* 
Timed Mutex = Timed Lock
A timed mutex is a synchronization primitive that allows a thread to attempt to acquire a lock with a timeout.
It provides the ability to specify a maximum duration to wait for the lock.
If the lock is not acquired within the specified time, the attempt fails.

Why Do We Need a Timed Mutex?
In some scenarios, you may want to avoid waiting indefinitely for a lock.
A timed mutex allows you to specify a timeout, improving responsiveness and preventing deadlocks in certain situations.

Notes:
1) std::timed_mutex is blocked till timeout_time or the lock is aquired and returns true if successfully aquired the lock, otherwise returns false.
2) std::timed_mutex is not recursive, so if the same thread tries to acquire the lock again, it will cause a deadlock.
3) std::timed_mutex is not copyable or movable, so it cannot be passed by value or stored in a container that requires copying or moving.
4) std::timed_mutex is not default constructible, so it must be initialized with a specific timeout duration before use.
5) Member functions : try, try_lock, try_lock_for, try_lock_until, unlock.
*/

#include <bits/stdc++.h>



std::timed_mutex mtx; // Timed mutex to protect shared data
int counter1 = 0; // Shared data
int counter2 = 0; // Shared data
void increment() {
    for (int i = 0; i < 9; i++) {
        if(mtx.try_lock_for(std::chrono::seconds(1U))) { // Try to lock the timed mutex with a timeout of 1 second
            counter1++;   // Critical section: modifying shared data
            mtx.unlock(); // Unlock the mutex after accessing the critical section
        } else {
            // Lock is already held by another thread, skip this iteration
            std::this_thread::yield(); // Yield to allow other threads to run
        }
    }
}

void increment1() {
    for (int i = 0; i < 9; i++) {
        auto now = std::chrono::steady_clock::now();
        if(mtx.try_lock_until(now + std::chrono::seconds(1U))) { // Try to lock the timed mutex until a specific time point
            counter2++;   // Critical section: modifying shared data
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
    std::thread t3(increment1);
    std::thread t4(increment1);
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << "Final counter1 value: " << counter1 << std::endl; // Output the final value of the counter1
    std::cout << "Final counter2 value: " << counter2 << std::endl; // Output the final value of the counter2
    return 0;
}