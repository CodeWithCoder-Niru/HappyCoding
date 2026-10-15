/*
 Recursive Mutex in C++
A recursive mutex is a synchronization primitive that allows the same thread to acquire the lock multiple times without
causing a deadlock. It keeps track of the number of times the lock has been acquired by the owning thread 
and allows it to acquire the lock again without blocking.

Why Do We Need a Recursive Mutex?
In some scenarios, a thread may need to acquire the same lock multiple times within the same execution context.
For example, if a function that acquires a lock calls another function that also tries to acquire the same lock,
a recursive mutex allows the thread to acquire the lock again without causing a deadlock.
*/

#include <bits/stdc++.h>


std::recursive_mutex recursiveMutex;
std::mutex coutMutex;

void recursiveFunction(int count) {
    if (count <= 0) return;

    std::lock_guard<std::mutex> lock{coutMutex};

    std::cout << "Lock acquired, count: " << count << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    recursiveFunction(count - 1);

    std::cout << "Lock released, count: " << count << std::endl;
}

int main() {
    std::thread t1(recursiveFunction, 5);
    std::thread t2(recursiveFunction, 5);
    t2.join();
    t1.join();

    return 0;
}
