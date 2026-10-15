/**
 * https://leetcode.com/problems/range-sum-query-immutable/description/?envType=problem-list-v2&envId=array
 * 
 */

#include <bits/stdc++.h>
    std::vector<int> num{-2,0,3,-5,2,-1};
class NumArray {
public:
    std::vector<int> prefix;
    NumArray(std::vector<int>& nums) {

        int n = nums.size();
        prefix.resize(n + 1, 0);
        for(auto i = 0 ; i <nums.size(); i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }
        for (auto itr:prefix) {
            std::cout <<itr<< " ";
        }

    }
    
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

int main() {

    NumArray *obj = new NumArray(num);
    int value = obj->sumRange(0, 5);
    std::cout << value <<std::endl;

    return 0;
}