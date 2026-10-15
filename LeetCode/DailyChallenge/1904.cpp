/*https://leetcode.com/problems/count-the-number-of-fair-pairs/description/?envType=daily-question&envId=2025-04-19*/
#include<bits/stdc++.h>

/*Time compixity o(n2)*/
class Solution {
    public:
        long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
            int cnt = 0;
            int size = nums.size();
            for(auto i = 0; i< size ; i++) {
                for(auto j=i+1; j< size; j++){
                    int sum = nums[i]+nums[j];
                    if(i>=0 && i<j && j<size && sum >= lower && sum <= upper) {
                        cnt++;
                    }

                }
            }
            return cnt;
        }
    };

int main() {
    Solution s1;
    std::vector<int> nums = {1,7,9,2,5};
    long long result = s1.countFairPairs(nums, 11, 11);
    std::cout<<"Result:"<<result;
}

/*Time complixity o(n logn)*/
/*
long long countFairPairs(vector<int>& nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    long long count = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int left = lower - nums[i];
        int right = upper - nums[i];
        auto l = lower_bound(nums.begin() + i + 1, nums.end(), left);
        auto r = upper_bound(nums.begin() + i + 1, nums.end(), right);
        count += r - l;
    }
    return count;
}

*/