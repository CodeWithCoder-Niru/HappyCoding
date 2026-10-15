/**List difference between reference and Pointers 
1. Syntax: References use the & symbol, while pointers use the * symbol.
2. Nullability: References cannot be null, while pointers can be null.
3. Reassignment: References cannot be reassigned to refer to a different object after initialization, while pointers can be reassigned to point to different objects.
4. Memory management: References do not require explicit memory management, while pointers may require manual memory management (e.g., using new and delete).
5. Dereferencing: References are automatically dereferenced, while pointers require explicit dereferencing using the * operator.
6. Usage: References are typically used for function parameters and return types to avoid copying, while pointers are often used for dynamic memory allocation and data structures like linked lists and trees.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int v=5;
    int &ref=v;
    ref =10;


    int *x = &ref;
    *x = 20;
    std::cout<<"X value:" << *x <<std::endl;
    std::cout<<"ref value:" << ref <<std::endl;

int a = 10;
int *b = &a;
int **c = &b;

std::cout<<"v value:" << v <<std::endl;
std::cout<<"ref value:" << ref <<std::endl;

std::cout<<"a value: " << a <<std::endl;
std::cout<<"a adderess: " << &a <<std::endl;
std::cout<<"b value: " << b <<std::endl;
std::cout<<"b adderess: " << &b <<std::endl;
std::cout<<"b dereference : " << *b <<std::endl;
std::cout<<"c value : " << ***&c <<std::endl;
}