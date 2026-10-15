/*https://leetcode.com/problems/build-array-from-permutation/?envType=daily-question&envId=2025-05-06*/
#include<bits/stdc++.h>
class Solution {
    public:
        std::vector<int> buildArray(std::vector<int>& nums) {
            std::vector<int> ans;
            for(auto i=0;i<nums.size();i++) {
                ans.emplace_back(nums.at(nums[i]));
        }
        return ans;
    }
};

int main(){
    Solution S1;
    std::vector<int> nums = {0,2,1,5,3,4};
    std::vector<int> ans = S1.buildArray(nums);
    for(auto &itr:ans) {
        std::cout<< itr ;
    }
}