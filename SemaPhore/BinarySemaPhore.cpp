/**
 * What is SemaPhore?
 * A semaphore is a synchronization primitive used to control access to a common resource in a concurrent system such as a multitasking operating system. 
 * A binary semaphore is a type of semaphore that can only take the values 0 and 1, effectively acting as a lock.
 * 
 * Example:
 * Consider a shared printer in an office. Only one person can use the printer at a time.
 * A binary semaphore can be used to ensure that only one person accesses the printer at any given moment.
 */

#include <bits/stdc++.h>
#include <semaphore>



std::binary_semaphore smphSigMainToThrd{0};
std::binary_semaphore smphSigThrdToMain{0};

void workerFunction(){

    smphSigMainToThrd.acquire(); // Wait for signal from main thread

    std::cout<< "Worker thread received signal from main thread." << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(3)); // Simulate work

    std::cout<< "Worker thread completed work and is signaling main thread." << std::endl;

    smphSigThrdToMain.release(); // Signal main thread that work is done

}

int main(){

    std::thread workerThread(workerFunction);

    std::cout<< "Main thread signaling worker thread to start work." << std::endl;
    smphSigMainToThrd.release(); // Signal worker thread to start work

    smphSigThrdToMain.acquire(); // Wait for signal from worker thread
    std::cout<< "Main thread received signal from worker thread that work is done." << std::endl;

    workerThread.join(); // Ensure the worker thread has finished before exiting
    return 0;
}