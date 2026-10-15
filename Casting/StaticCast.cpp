/** 
 * Static Cast in C++
 * Static cast is used for compile-time type casting.
 * It is used to convert one data type to another.
 * It performs no runtime checks, so it is faster but less safe.
 * Use it when you are sure about the types involved.
 * Example:
 * int a = 10;
 * double b = static_cast<double>(a);
 * Syntax: static_cast<new_type>(expression)
 */

 // Use it when using conversion operator and converion constructor

#include <bits/stdc++.h>

// class A {
//     public:
//     operator int() {
//         return 42;
//     }
// };

// int main() {
//     A a;
//     int x = static_cast<int>(a); // Uses the conversion operator to convert A to int
//     std::cout << "The value of x is: " << x << std::endl; // Output: The value of x is: 42
//     return 0;
// }

// static_cast not allow the char* to int* conversion but in c style cast it is allowed but fails at runtime

int main(){
    char* str = "Hello";
    int* ptr = static_cast<int*>(str); // Compile-time error: cannot convert from 'char*' to 'int*'
    int* ptr2 = (int*)str; // Allowed in C-style cast, but leads to undefined behavior at runtime
    return 0;
}

// static_cast avoid the cast from dervied class to private base class but in c style cast it is allowed but fails at runtime

class base{};
class derived : private base{};

int main() {
    derived d;
    base* b1 = static_cast<base*>(&d); // Compile-time error: cannot cast from 'derived*' to 'base*' due to private inheritance
    base* b2 = (base*)&d; // Allowed in C-style cast, but leads to undefined behavior at runtime
    return 0;
}

//it will be used in void* to other type of pointer conversion