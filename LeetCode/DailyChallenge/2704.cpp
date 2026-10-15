/*https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/?envType=daily-question&envId=2025-04-27*/
#include<bits/stdc++.h>
class Solution {
    public:
        int countSubarrays(std::vector<int>& nums) {
            int n = nums.size();
            int count = 0;
            for (int i = 0; i <= n - 3; ++i) {
                if (nums[i] + nums[i+2] == nums[i+1] / 2.0) {
                    count++;
                }
            }
            return count;
        }
};
int main() {
    Solution S1;
    std::vector<int> nums{1,1,1};
    long long Result = S1.countSubarrays(nums);
    std::cout<<Result;
}