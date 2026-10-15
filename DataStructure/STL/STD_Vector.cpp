
//NOTES:
//1. vector is sequence container and also known as dynamic array or array list
//2. Its size can grow and shrink dynamically and no need to provide size at compile time.

/* ELEMENT ACCESS
    AT(), [], front(), back(), data()
*/

/* MODIFIERS:
    insert(), emplace(), push_back(), emplace_back() pop_back(), resize(), swap(), erase(), clean()
*/
#include<bits/stdc++.h>
#include<vector>

int main() {
    std::vector<int> MyVec;
    MyVec.reserve(10);
    for(int i=0;i<33;i++) {
        MyVec.push_back(i);
        std::cout<<"size: " <<MyVec.size() << "     Capacity: " << MyVec.capacity()<<std::endl;
    }
    return 0;

}