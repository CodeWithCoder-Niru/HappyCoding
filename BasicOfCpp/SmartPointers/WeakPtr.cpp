/** Weak ptr is a smart pointer that holds a non-owning ("weak") reference to an object that is managed by std::shared_ptr.
It is used to break circular references in shared_ptr, allowing the object to be destroyed when the
last shared_ptr managing it is destroyed or reset. Weak ptr does not affect the reference count of the object it points to.
Advantages of weak_ptr:
1. Breaks circular references: weak_ptr can be used to break circular references in shared_ptr
2. Non-owning reference: weak_ptr does not affect the reference count of the object it points to, allowing for more flexible resource management.
3. Safe access: weak_ptr provides a way to safely access the object it points to, even if the object has been destroyed, by using the lock() method to obtain a shared_ptr.
Drawbacks of weak_ptr:
1. No ownership: weak_ptr does not own the object it points to, so it cannot be used to manage the lifetime of the object directly.
2. Requires shared_ptr: weak_ptr can only be used in conjunction with shared_ptr, which can add complexity to the code and may not be suitable for all use cases.
 */

#include <bits/stdc++.h>


int main() {
    std::shared_ptr<int> sharedPtr = std::make_shared<int>(42); // Create a shared_ptr to an integer
    std::weak_ptr<int> weakptr = sharedPtr; // Create a weak_ptr that points to the same integer

    std::cout << "Shared pointer value: " << *sharedPtr << std::endl; // Output: Shared pointer value: 42
    std::cout << "Weak pointer use count: " << weakptr.use_count() << std::endl; // Output: Weak pointer use count: 1   
    std::cout << "Shared pointer use count: " << sharedPtr.use_count() << std::endl; // Output: Shared pointer use count: 1
    std::cout << "Is weak pointer expired? " << std::boolalpha << weakptr.expired() << std::endl; // Output: Is weak pointer expired? false

    if(std::shared_ptr<int> sharedptr2 = weakptr.lock()) {
        std::cout << "Locked weak pointer value: " << *sharedptr2 << std::endl; // Output: Locked weak pointer value: 42
    } else {
        std::cout << "Weak pointer is expired." << std::endl;
    }

    sharedPtr.reset(); // Reset the shared_ptr, which will destroy the integer
    std::cout << "After resetting shared pointer:" << std::endl;
    std::cout << "Is weak pointer expired? " << std::boolalpha << weakptr.expired() << std::endl; // Output: Is weak pointer expired? true
    std::cout << "Weak pointer use count: " << weakptr.use_count() << std::endl; // Output: Weak pointer use count: 0
    std::cout << "Shared pointer use count: " << sharedPtr.use_count() << std::endl; // Output: Shared pointer use count: 0
    return 0;
}