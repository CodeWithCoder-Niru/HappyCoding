/**
 * Move Constructor in C++
 * A move constructor is a special constructor in C++ that is used to create a new object by transferring the resources from an existing object, rather than copying them.
 * It is called when an object is initialized with an rvalue (temporary object) of the same class, passed by rvalue
 * reference to a function, or returned by value from a function.
 * Why Do We Need a Move Constructor?
1) To optimize performance: A move constructor allows you to transfer resources from a temporary object to a new object without the overhead of copying,
which can improve performance, especially for classes that manage resources
2) To enable move semantics: Move constructors are a key component of move semantics in C++,
 which allows for efficient transfer of resources and can help to avoid unnecessary copying of objects.
3) To manage resources properly: A move constructor can help to ensure that resources are properly managed and
released when an object is moved, preventing issues like double deletion or memory leaks.
4) To enable the use of objects in situations where moving is required,
 such as when passing objects by rvalue reference to functions or returning objects by value from functions.
 */

#include <bits/stdc++.h>

class MyClass {
    public:
        int* data; // Pointer to dynamically allocated memory

    public:
        MyClass() {
            data = new int(20);
            std::cout << "Default constructor called!" << std::endl;
        }
        MyClass (const MyClass &obj) {
            data = new int(*obj.data); // Perform a deep copy of the data member to ensure that the new object has its own copy of the resource
            std::cout << "Copy constructor called!" << std::endl;
        }
        MyClass (MyClass &&obj) {
            data = obj.data; // Transfer ownership of the resource from the source object to the new object
            obj.data = nullptr; // Set the source object's pointer to nullptr to prevent double deletion
            std::cout << "Move constructor called!" << std::endl;
        }
        ~MyClass() {
            delete data; // Release the dynamically allocated memory
            std::cout << "Destructor called!" << std::endl;
        }
};

int main() {
    MyClass obj1; // Default constructor will be called here
    MyClass obj2 = obj1; // Copy constructor will be called here to create obj2 as a copy of obj1
    MyClass obj3 = std::move(obj1); // Move constructor will be called here to create obj3 by moving resources from obj1

    std::cout << "obj1 data: " << (obj1.data ? *obj1.data : 0) << std::endl; // Output the data member of obj1, which should be 0 since it has been moved
    std::cout << "obj2 data: " << *obj2.data << std::endl; // Output the data member of obj2, which should be the same as obj1 since obj2 is a copy of obj1
    std::cout << "obj3 data: " << *obj3.data << std::endl; // Output the data member of obj3, which should be the same as obj1 since obj3 is a move of obj1

    return 0;
}

    // Copy constructor
    Buffer(const Buffer& other) {
        data = new int(*other.data);
    }

    // Copy assignment
    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }
        // Move constructor
    Buffer(Buffer&& other) {
        data = other.data;
        other.data = nullptr;
    }

    // Move assignment
    Buffer& operator=(Buffer&& other) {
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }