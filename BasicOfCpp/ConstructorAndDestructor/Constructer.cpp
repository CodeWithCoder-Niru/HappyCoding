//Can we call constructor and destructor explicitly in C++?
/*
    Yes, in C++, you can call constructors and destructors explicitly, but it is generally not recommended to do so. 

    1) Calling a constructor explicitly:
       You can create an object by calling its constructor directly, like this:
       MyClass obj = MyClass(); // This will call the default constructor of MyClass

    2) Calling a destructor explicitly:
       You can call a destructor explicitly using the delete operator for dynamically allocated objects, like this:
       MyClass* obj = new MyClass(); // Dynamically allocate an object
       delete obj; // This will call the destructor of MyClass  

**/

#include <bits/stdc++.h>

class MyClass {
public: 
    MyClass() {
        std::cout << "Constructor called!" << std::endl;
    }
    ~MyClass() {
        std::cout << "Destructor called!" << std::endl;
    }
};

int main() {
    MyClass(); // Constructor will be called here and the temporary object will be destroyed immediately after this line, so the destructor will also be called.
    MyClass().~MyClass(); // Explicitly calling the destructor, but this is not recommended as it can lead to undefined behavior if the object is used after this point.
    // Destructor will be called automatically when obj goes out of scope
    return 0;
}

