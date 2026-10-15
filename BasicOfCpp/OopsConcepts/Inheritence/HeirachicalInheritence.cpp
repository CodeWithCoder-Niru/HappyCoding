/** Hierarchical Inheritance in C++
In hierarchical inheritance, multiple classes are derived from a single base class. 
Each derived class inherits the properties and behaviors of the base class.
The syntax for hierarchical inheritance in C++ is as follows:


Problem with Hierarchical Inheritance:
❗ Problem
D inherits from both B and C
Both B and C inherit from A
So D has two copies of A

👉 When you call:

obj.show();

Compiler gets confused:

Should it use A from B?
Or A from C?

This ambiguity is the diamond problem.

When you write:

class B : virtual public A {};
class C : virtual public A {};

👉 It tells the compiler:

"Only create one shared copy of class A, even if it's inherited multiple times."
 */

#include <bits/stdc++.h>
using namespace std;

class A {
public:
    void show() {
        cout << "Class A\n";
    }
};

class B : virtual public A {};
class C : virtual public A {};

class D : public B, public C {};

int main() {
    D obj;
    obj.show();  // ✅ Works fine
}