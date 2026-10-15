/**
 * C++ const_cast operator is used to cast away the constness of a variable.
 * It can be used to modify a variable that is declared as const. 
 * However, it should be used with caution, as modifying a const variable can lead to undefined behavior if the variable was originally declared as const.
 * 
 * The syntax for const_cast is as follows:
 * const_cast<T>(V)
 * Where T is the type to which you want to cast and V is the variable you want to cast.
 * T must be a pointer or reference type.
 */


 #include <bits/stdc++.h>


 // When the actual referenced object/variable is not const

 int main() {

    int a = 10; //it should be noted that a is not a const variable but it is a const reference to an int variable, so it can be modified through the pointer obtained by const_cast
    const int *b1 = &a;

    int *c = const_cast<int*> (b1);
    *c = 15;

 }

 // When you dealing with third party library which has const in function parameter but
 // you want to modify the parameter