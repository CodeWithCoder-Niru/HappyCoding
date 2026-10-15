/** Multiple Inheritance in C++
In multiple inheritance, a class can be derived from more than one base class. 
The derived class inherits the properties and behaviors of all its base classes.
The syntax for multiple inheritance in C++ is as follows:
 */

#include <bits/stdc++.h>
class Base1 {
    public:
    void show_Base1() {
        std::cout << "Base1 class function called" << std::endl;
    }
};

class Base2 {
    public:
    void show_Base2() {
        std::cout << "Base2 class function called" << std::endl;
    }
};

class Derived : public Base1, public Base2 {
    public:
    void show_Derived() {
        std::cout << "Derived class function called" << std::endl;
    }
};

int main() {
    Derived d;
    d.show_Derived(); // Output: Derived class function called
    d.show_Base1(); // Output: Base1 class function called
    d.show_Base2(); // Output: Base2 class function called    
    return 0;
}