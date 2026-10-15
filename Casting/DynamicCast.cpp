
/**0. It used at run time to find out correct down-cast.
1: Need at least one virtual function in base class.
2: If the cast is successful, dynamic_cast returns a value of type new_type. 
3: If the cast fails and new_type is a pointer type, it returns a null pointer of that type.
4: If the cast fails and new_type is a reference type, it throws an exception that matches a handler of type std::bad_cast.

BOTTOM LINE:
1. work only on polymorphic base class (at least one virtual function in base class) because it uses this information to decide about wrong down-cast.
2. it is used for up-cast (D to B) and down-cast (B to D), but it is mainly used for correct downcast.
3. using this cast has run time overhead, because it checks object types at run time using RTTI (Run Time Type Information).
4. if we are sure that we will never cast to wrong object then we should aways avoid this cast and use static_cast.
*/

#include <bits/stdc++.h>

class Base {
    public:
    virtual void show() { // Need at least one virtual function in base class
        std::cout << "Base class function called" << std::endl;
    }
};

class derived1 : public Base {
    public:
    void show() override {
        std::cout << "Derived1 class function called" << std::endl;
    }
};

class derived2 : public Base {
    public:
    void show() override {
        std::cout << "Derived2 class function called" << std::endl;
    }
};

int main() {
    Base* b1 = new derived1();
    Base* b2 = new derived2();

    // Correct downcast
    derived1* d1 = dynamic_cast<derived1*>(b1);
    if (d1) {
        d1->show(); // Output: Derived1 class function called
    } else {
        std::cout << "Downcast failed for b1" << std::endl;
    }

    // Wrong downcast
    derived1* d2 = dynamic_cast<derived1*>(b2);
    if (d2) {
        d2->show();
    } else {
        std::cout << "Downcast failed for b2" << std::endl; // Output: Downcast failed for b2
    }

    delete b1;
    delete b2;

    return 0;
}