/**
 * Unique ptr is a smart pointer that owns and manages another object through a pointer and 
disposes of that object when the unique_ptr goes out of scope.
No two unique_ptr instances can manage the same object,
and the object is destroyed when the unique_ptr goes out of scope.*/

/**Advantages of unique_ptr:
1. Automatic memory management: unique_ptr automatically deallocates the memory it manages when it goes out of scope,
preventing memory leaks.
2. Exclusive ownership: unique_ptr ensures that only one unique
pointer can own a particular resource, preventing issues related to multiple ownership and dangling pointers.
3. Move semantics: unique_ptr supports move semantics, allowing ownership to be transferred efficiently without copying the underlying resource.
4. Better performance: unique_ptr is typically more efficient than shared_ptr because it does not require reference counting,
 making it a better choice when exclusive ownership is sufficient.

 Drawbacks of unique_ptr:
1. No shared ownership: unique_ptr does not allow multiple pointers to share ownership of the same resource,
 which can be a limitation in certain scenarios where shared ownership is required.
2. Cannot be copied: unique_ptr cannot be copied, only moved, which can be restrictive in some situations.**/

#include <bits/stdc++.h>
#include <memory>


class UniquePtr {
    public:
        UniquePtr() {
            std::cout << "UniquePtr constructor called" << std::endl; 
        }
        ~UniquePtr() {
            std::cout << "UniquePtr destructor called" << std::endl;
        }

};

int main() {
    // Create a unique_ptr to an integer
    std::unique_ptr<UniquePtr> ptr1 = std::make_unique<UniquePtr>();
    // std::unique_ptr<int> ptr2 = std::make_unique<int>(20); // Preferred way to create unique_ptr
    
    // // Access the value
    // std::cout << "Value: " << *ptr1 << std::endl; // Output: Value: 10
    
    // // Transfer ownership to another unique_ptr
    // std::unique_ptr<UniquePtr> ptr2 = std::move(ptr1);
    
    // // Check if ptr1 is now empty
    // if (!ptr1) {
    //     std::cout << "ptr1 is empty" << std::endl; // Output: ptr1 is empty
    // }
    
    // // Access the value through ptr2
    // std::cout << "Value: " << *ptr2 << std::endl; // Output: Value: 10
    
    return 0;
}