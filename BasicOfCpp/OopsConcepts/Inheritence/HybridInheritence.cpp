/** Hybrid Inheritance in C++
In hybrid inheritance, a combination of two or more types of inheritance is used. 
It allows a class to inherit from multiple classes, which can themselves be part of different inheritance hierarchies.
The syntax for hybrid inheritance in C++ is as follows:

 */

#include <bits/stdc++.h>

class A {
    public:
    void show_A() {
        std::cout << "Class A function called" << std::endl;
    }
};

class B : public A {
    public:
    void show_B() {
        std::cout << "Class B function called" << std::endl;
    }
};

class C : public A {
    public:
    void show_C() {
        std::cout << "Class C function called" << std::endl;
    }
};

class D : virtual public B, virtual public C {
    public:
    void show_D() {
        std::cout << "Class D function called" << std::endl;
    }
};

int main() {
    D d;
    d.show_D(); // Output: Class D function called
    d.show_B(); // Output: Class B function called
    d.show_C(); // Output: Class C function called
    d.show_A(); // Output: Class A function called
    return 0;
}