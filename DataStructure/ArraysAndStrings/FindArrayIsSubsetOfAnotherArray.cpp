#include <bits/stdc++.h>


bool isSubset(std::vector<int>& arr1, std::vector<int>& arr2) {
    std::unordered_map<int, int>freq;

    for(int num : arr1) {
        freq[num]++;
    }

    for(int num : arr2) {
        if(freq[num] == 0) {
            return false;
        }
        freq[num]--;
    }

    return true;
}


int main()  {
    std::vector<int> arr1 = {1, 2, 2, 3};
    std::vector<int> arr2 = {2, 2};

    if (isSubset(arr1, arr2))
        std::cout << "arr2 is subset of arr1";
    else
        std::cout << "arr2 is not subset of arr1";

    return 0;
}