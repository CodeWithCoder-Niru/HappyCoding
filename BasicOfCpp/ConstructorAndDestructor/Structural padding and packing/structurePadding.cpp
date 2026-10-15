/**
 * 
 */


#include <bits/stdc++.h>


struct A {
    int x;
    double d;
};

//in first struct it will consider large data type and allocate memory for that
//eg :: d --> 8byte so it will first allocate 8 byte memory segment for x = {x,x,x,x,_,_,_,_} and again it will allocate the 8byte for d so total 16
//


//in 2nd struct it will go inside A and take the large data type i.e 8byte, so it will allocate the 8 byte memory for y and k rest is 16 byte for A total 24

struct B {
    int y; 
    int k;
    A obj;

};

//in C struct it will different 

struct C {
    int y; //8byte (4byte + 4byte padding)
    A obj; //16byte
    int k; //8byte (4byte + 4byte padding`)
};

int main() {
    std::cout << sizeof(C);

    return 0;
}