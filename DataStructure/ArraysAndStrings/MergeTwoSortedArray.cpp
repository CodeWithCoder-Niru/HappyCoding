#include <bits/stdc++.h>




std::vector<int> MergeSortedArray(std::vector<int> &arr1, std::vector<int> &arr2) {

    std::vector<int> result;
    int i = 0;
    int j = 0;

    while(i < arr1.size() && j < arr2.size()) {
        if(arr1[i] < arr2[j]) {
            result.push_back(arr1[i]);
            i++;
        } else {
            result.push_back(arr2[j]);
            j++;
        }
    }

    while(i < arr1.size()) {
        result.push_back(arr1[i]);
        i++;
    }

    while(j < arr2.size()) {
        result.push_back(arr1[i]);
        j++;
    }
    return result;

} 

int main() {
    std::vector<int> arr1 = {5, 6, 6, 7, 8, 9};
    std::vector<int> arr2 = {1, 2, 4, 5};

    std::vector<int> result = MergeSortedArray(arr1, arr2);

    for(auto it:result) {
        std::cout<< it << " ";
    }
}