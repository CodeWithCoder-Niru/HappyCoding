/**Shared ptr is a smart pointer that retains shared ownership of an object through a pointer.
Multiple shared_ptr instances can manage the same object,
and the object is destroyed when the last shared_ptr managing it is destroyed or reset.*/

/**Advantages of shared_ptr:
1. Shared ownership: multiple shared_ptr instances can share ownership of the same resource, allowing for flexible resource management.
2. Automatic memory management: shared_ptr automatically deallocates the memory it manages when the last shared_ptr goes out of scope, preventing memory leaks.
3. Thread-safe reference counting: shared_ptr uses atomic operations for reference counting, making it safe to use in multithreaded environments.*/

/**Drawbacks of shared_ptr:
1. Overhead: shared_ptr incurs additional overhead due to reference counting, which can impact performance compared to unique_ptr.
2. Risk of cyclic references: if two or more shared_ptr instances form a cycle, the reference count may never reach zero, leading to memory leaks.*/

#include <bits/stdc++.h>
#include <memory>



class SharedPtr {
    public:
        SharedPtr() {
            std::cout << "SharedPtr constructor called" << std::endl; 
        }
        ~SharedPtr() {
            std::cout << "SharedPtr destructor called" << std::endl;
        }

};

int main() {
    // Create a shared_ptr to an integer
    std::shared_ptr<SharedPtr> ptr1 = std::make_shared<SharedPtr>();
    // std::shared_ptr<int> ptr2 = std::make_shared<int>(20); // Preferred way to create shared_ptr
    
    // // Access the value
    // std::cout << "Value: " << *ptr1 << std::endl; // Output: Value: 10
    
    // // Create another shared_ptr that shares ownership of the same object
    // std::shared_ptr<SharedPtr> ptr2 = ptr1;
    
    // // Check the reference count
    // std::cout << "Reference count: " << ptr1.use_count() << std::endl; // Output: Reference count: 2
    
    // // Reset one of the shared_ptr instances
    // ptr1.reset();
    
    // // Check the reference count again
    // std::cout << "Reference count after reset: " << ptr2.use_count() << std::endl; // Output: Reference count after reset: 1
    
    return 0;
}