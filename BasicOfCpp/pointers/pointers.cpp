#include<bits/stdc++.h>
using namespace std;

// int* getValue() {
//     int x=10;

//     return &x;
// }

int add(int a, int b) {
    return a+b;
}
int sub(int a, int b) {
    return a-b;
}

int main() {
    //Null pointer
    #if 0
    int *p = 0;
    if(p == nullptr) {
        std::cout<<"true" << *p;
    }
    else {
        std::cout<<"false" << *p;
    }
    #endif

    //void pointer
    #if 0
    int x = 42;
    
    // void pointer holding address of an int
    void* ptr = &x;

    // Error: cannot dereference void pointer
    // cout << *ptr; 

    // Typecast before dereferencing
    cout << "Value pointed by void pointer: " << *(static_cast<int*>(ptr)) << endl;
    #endif

    //Dangling pointer
    #if 0
    int *ptr = getValue();
    cout<<"Pinter value:" <<*ptr;
    #endif

    // constant pointer(adderess can not be changed)
    #if 0
    char ch, c;
    char* const ptr = &ch; //ptr assigned with the ch adderess
    // ptr = & c;  //wrong
    *ptr = 'd';

    #endif

    // pointer to constant(value can not be change)
    #if 0
    char ch = 'c', c;
    const char *ptr = &ch;
    // ptr = 'd';
    //*ptr = 'd'; //wrong
    ptr = & c;
    #endif

    // Array of pointers
    #if 0
    int a = 5; int b = 10; int c = 15;
    int *ptr = &a;
    int *ptr1 = &b;
    int *ptr2 = &c;

    void *ptrArray[3];
    ptrArray[0] = ptr;
    ptrArray[1] = ptr1;
    ptrArray[2] = ptr2;

    for (auto it:ptrArray) {
        std::cout<< *(static_cast<int*>(it));
    }
    #endif

    // Array of function pointers
    #if 1
    // int (*fptrArray[2]) (int, int); // c style

    std::array<std::function<int(int, int)>, 2> fptrArray; //c++ style

    fptrArray[0] = &add;
    fptrArray[1] = &sub;

    std::cout<< "Addition: "<<fptrArray[1](2,4);
    #endif
    return 0;
}