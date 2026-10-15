/**
 * This file demonstrates the use of explicit constructors in C++.
 * Explicit constructors are constructors that are declared with the `explicit` keyword.
 * The purpose of using explicit constructors is to prevent implicit conversions that can lead to unexpected behavior in
 * certain situations. By marking a constructor as explicit, you ensure that it can only be called explicitly,
 * which helps to avoid unintended type conversions and improves code clarity.
 */


 //without explicit keyword
#include <iostream>
class MyClass {
public:
    MyClass(int x) {
        // constructor
    }
};

int main() {
    MyClass obj = 10;   // Allowed: implicit conversion from int to MyClass
}

//With explicit keyword
class MyClass {
public:
    explicit MyClass(int x) {
        // constructor
    }
};

int main() {
    MyClass obj1(10);      // OK: direct initialization
    MyClass obj2 = 10;     // Error: implicit conversion not allowed
}

/**
When should you use explicit?
Use explicit for:

Constructors that can be called with one argument (or multiple arguments where all but one have default values).
Conversion operators (since C++11)

*/

