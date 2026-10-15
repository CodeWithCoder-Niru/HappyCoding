/** Multilevel Inheritance in C++
In multilevel inheritance, a class is derived from another derived class, forming a chain of inheritance.
The derived class inherits the properties and behaviors of its immediate base class, which in turn may have inherited from its own base class.
The syntax for multilevel inheritance in C++ is as follows:
 */

#include <bits/stdc++.h>
class Base {
    public:
    void show_Base() {
        std::cout << "Base class function called" << std::endl;
    }
};

class Derived1 : public Base {
    public:
    void show_Derived1() {
        std::cout << "Derived1 class function called" << std::endl;
    }
};

class Derived2 : public Derived1 {
    public:
    void show_Derived2() {
        std::cout << "Derived2 class function called" << std::endl;
    }
};

int main() {
    Derived2 d2;
    d2.show_Derived2(); // Output: Derived2 class function called
    d2.show_Derived1(); // Output: Derived1 class function called
    d2.show_Base(); // Output: Base class function called    
    return 0;
}