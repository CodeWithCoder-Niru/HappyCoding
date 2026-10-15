/**
 * find missing number in array
 * 
 * input {1,2,4,5,6,7,9}
 * output 8
 */


#include <bits/stdc++.h>

void findMissingNum(std::vector<int> &num) {
    int max = 0, i=0;
    std::unordered_set<int> mSet;
    for(auto itr:num)
        mSet.insert(itr);
    for(auto itr: num) {
        if(itr > max)
            max = itr;
    }
    // num.resize(max);

    while(i < max) {
        auto itr = mSet.find(i);
        if(itr == mSet.end()) {
            std::cout<<" "<<i ;
        }
        i++;
    }

}


int main() {
    std::vector<int> array{2,7,11,15, 5, 4, 4, 6};
    findMissingNum(array);

    return 0;
}