/**
 * 
 * intput n=4 array[4] = {0,3,1,2}
 * output = -1
 * 
 * input n=5 array[5] = {2,3,1,2,3}
 * output = 2,3
 */

#include <bits/stdc++.h>

void findDuplicate(std::vector<int> &list) {

    std::map<int, int> mMap;

    for(auto const itr:list) {
        mMap[itr]++;
    }

    for (auto var:list) {
        if(mMap[var] > 1) {
            std::cout<< var;
            mMap[var] = 0;
            //how to remove from the list?
            list.erase(std::remove(list.begin(), list.end(), var), list.end());

        } else {

        }
    }

    for(auto var:list) {
        std::cout<< var << " ";
    }

}


int main() {

    std::vector<int> array{4,4,5,5,6,3,1,7,8,8,6,4,5};
    findDuplicate(array);
}