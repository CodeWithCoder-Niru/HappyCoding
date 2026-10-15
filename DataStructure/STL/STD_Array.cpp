// T : type
// N : size
//Syntax: std::array<T, N>my_array;
/**
 * 1. Array is a container that encapsulates fixed size array
 * 2. Array size is needed at compiletime
 * 3. Assign by value is actually by value
 */
/*Access Elements:
 1.at()
 2.[]
 3.front()
 4.back()
 5.data()
 6.fill()*/


#include<bits/stdc++.h>
#include<array>

int main() {
    std::array<int, 5> myarray;
    myarray = {1,2,3,4,5};
    for(int i=0;i<5;i++) {
        myarray.back();
        std::cout<<"Array Values:"<<*myarray.crend()<<std::endl;
    }
    return 0;
}
