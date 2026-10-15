/** Single Inheritence in C++
In single inheritance, a class is derived from a single base class. The derived class inherits the
properties and behaviors of the base class. The derived class can also have its own additional members and functions.
In single inheritance, the derived class can access the public and protected members of the base class,
but it cannot access the private members of the base class directly. However, it can access them through public or protected member functions of the base class.
The syntax for single inheritance in C++ is as follows:
 */

#include <bits/stdc++.h>
class Base {
    public:
    void show_Base() {
        std::cout << "Base class function called" << std::endl;
    }
};

class Derived : public Base {
    public:
    void show_Derived() {
        std::cout << "Derived class function called" << std::endl;
    }
};

int main() {
    Derived d;
    d.show_Derived(); // Output: Derived class function called
    d.show_Base(); // Output: Base class function called    
    return 0;
}