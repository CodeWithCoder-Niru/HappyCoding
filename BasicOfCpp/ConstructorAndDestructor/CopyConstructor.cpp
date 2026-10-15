/**
 * 
 * Copy Constructor in C++
 * A copy constructor is a special constructor in C++ that is used to create a new object as a copy of an existing object.
 * It is called when an object is initialized with another object of the same class, passed by value to a function, or returned by value from a function.
 * 
 * Why Do We Need a Copy Constructor?
 * 1) To create a new object as a copy of an existing object, ensuring that the new object has the same state as the original object.
 * 2) To manage resources properly, especially when the class contains pointers or dynamic memory allocation. 
 * A copy constructor can perform a deep copy to ensure that the new object has its own copy of the resources, preventing issues like double deletion or memory leaks.
 * 3) To enable the use of objects in situations where copying is required, such as when passing objects by value to functions or returning objects by value from functions.
 * 
 */
#include <bits/stdc++.h>

// class Myclass {

//     public:
//         int data; // Example member variable

//     public:
//         Myclass() {
//             data = 20;
//             std::cout <<"Default constructor called!" << std::endl;
//         }
//         Myclass(const Myclass &obj) {
//             data = obj.data; // Copy the data member from the original object to the new object
//             // Copy the data member from the original object to the new object
//             // This is the copy constructor, which takes a reference to an object of the same class as a parameter.
//             // why we need to use reference and const here?
//             // 1) Using a reference allows us to avoid unnecessary copying of the object, which can cause the recursion of the copy constructor,
//             //    leading to infinite recursion and eventually a stack overflow.
//             //    By passing the object by reference, we can access the original object without creating a new copy. 
//             // 2) Using const ensures that the original object passed to the copy constructor cannot be modified,
//             //    which is important for maintaining the integrity of the original object and preventing unintended side effects.
//             std::cout <<"Copy constructor called!" << std::endl;
//         }
// };

// int main() {
//     Myclass obj1; // Default constructor will be called here
//     Myclass obj2 = obj1 ; // Copy constructor will be called here to create obj2 as a copy of obj1  

//     std::cout << "obj1 data: " << obj1.data << std::endl; // Output the data member of obj1
//     std::cout << "obj2 data: " << obj2.data << std::endl; // Output the data member of obj2, which should be the same as obj1 since obj2 is a copy of obj1
//     return 0;
// }

//Deep Copy vs Shallow Copy
/**
 * Deep Copy: A deep copy creates a new object and copies all the data from the original object to the new object, including any dynamically allocated memory.
 * This means that the new object has its own copy of the resources, and changes to one object do not affect the other object.
 * A deep copy is typically implemented in a copy constructor by allocating new memory for the resources and copying the values from the original object to the new object.
 */

class MyClass {
    public:
        int* data; // Pointer to dynamically allocated memory

        MyClass(int value) {
            data = new int(value);
            std::cout << "Default constructor called!" << std::endl;
        }
        MyClass (const MyClass &obj) {
            data = new int(*obj.data);
            std::cout << "Copy constructor called!" << std::endl;
        }
};

int main() {
    MyClass obj1(20);
    MyClass obj2 = obj1;
     

    // *obj2.data = 40;

    std::cout<< "obj1 data: " << *obj1.data <<std::endl;
    std::cout<< "obj2 data: " << *obj2.data <<std::endl;
}

//Shallow Copy: A shallow copy creates a new object and copies the values of the data members from the original object to the new object.
// However, if the class contains pointers or dynamic memory allocation, a shallow copy will only copy the pointer values, not the actual data they point to.
// This means that both the original object and the new object will point to the same memory location, and changes to one object will affect the other object.
// A shallow copy is typically implemented in a copy constructor by simply copying the pointer values from the original object to the new object, without allocating new

// class MyClass {
//     public:
//         int* data; // Pointer to dynamically allocated memory
//         MyClass() {
//             data = new int(20);
//             std::cout << "Default constructor called!" << std::endl;
//         }
//         MyClass (const MyClass &obj) {
//             data = obj.data; // Shallow copy: copying the pointer value, not the actual data
//         }
// };

// int main() {
//     MyClass obj1;
//     MyClass obj2 = obj1;

//     *obj2.data = 40; // Modifying the data through obj2 will affect obj1 since both obj1 and obj2 point to the same memory location

//     std::cout<< "obj1 data: " << *obj1.data <<std::endl; // Output will be 40, which shows that obj1's data has been modified through obj2
//     std::cout<< "obj2 data: " << *obj2.data <<std::endl; // Output will also be 40, confirming that both obj1 and obj2 point to the same memory location
//     return 0;
// }

//Shallow copy vs Deep copy

// In summary, a deep copy creates a new object with its own copy of the resources, while
// a shallow copy creates a new object that shares the same resources as the original object.

// A deep copy is typically implemented in a copy constructor by allocating new memory for the resources and 
// copying the values from the original object to the new object,  
// while a shallow copy simply copies the pointer values from the original object to the new object without allocating new memory for the resources.

// In general, a deep copy is preferred when the class contains pointers or dynamic memory allocation to ensure that each object
//  has its own copy of the resources and to prevent issues like double deletion or memory leaks.