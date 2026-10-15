/**
 * Reorder the array sach that all 0 should comes at last position
 */

#include<bits/stdc++.h>

void reorderArray(std::vector<int> list) {
    std::vector<int> result;
    for(auto itr:list) {
        if(itr != 0) {
            result.push_back(itr);
        }
    }

    while(result.size() < list.size()) { 
        result.push_back(0);
    }

    for(auto itr:result) {
        std::cout<< "list are: " << itr;
    }


}


int main() {

    std::vector<int> vec{0,5,0,5,0,9,0,9,6};  //output looks like : 1,3,5,4,9,6,0,0,0
    reorderArray(vec);

}