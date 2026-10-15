/**
 * Constructor Delegation in C++
 * Constructor delegation is a feature in C++ that allows one constructor to call another constructor within the same class.
 * This can help to avoid code duplication and improve code maintainability by centralizing common initialization
 * logic in a single constructor, which can then be reused by other constructors.
 * 
 * Why Do We Need Constructor Delegation?
 * 1) To avoid code duplication: Constructor delegation allows you to centralize common initialization logic in a single constructor,
 *  which can then be reused by other constructors. This helps to reduce code duplication
 * 2) To improve code maintainability: By centralizing common initialization logic in a single constructor,
 *  it becomes easier to maintain and update the code.
 * 3) To provide multiple ways to initialize an object: Constructor delegation allows you to provide multiple constructors with different parameters,
 *  which can call a common constructor to initialize the object in different ways.
 * 
 * Drawbacks of Constructor Delegation:
 * 1) Increased complexity: Constructor delegation can make the code more complex and harder to understand
 * 2) Performance overhead: Constructor delegation can introduce additional function calls, 
 * which may lead to a slight performance overhead compared to directly initializing the object in each constructor.
 * 3) Limited flexibility: Constructor delegation may not be suitable for all scenarios, 
 * especially when the initialization logic is complex or requires different parameters for each constructor.
 * 4) Potential for infinite recursion: If not implemented carefully, constructor delegation can lead to infinite recursion if constructors call each other in a circular manner.
 */


#include <bits/stdc++.h>


class MyClass {
    public:
        int _x, _y; // Example member variable
    public:
        MyClass(): MyClass(_x, _y) {
            _x = 10;
            _y = 20;
        }
        MyClass(int value): MyClass(_x, _y) {
            _x = value;
            _y = value;
        }
        MyClass(int value1, int value2) : _x(value1), _y(value2){

        }

        void print() {
            std::cout << "Value _x :" <<_x <<std::endl;
            std::cout << "Value _y :" <<_y <<std::endl;
        }
};

int main() {

    MyClass obj;
    MyClass obj1(10);
    MyClass obj2(20, 40);

    obj.print();
    obj1.print();
    obj2.print();

    return 0;

}