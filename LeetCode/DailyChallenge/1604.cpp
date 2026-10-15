/*https://leetcode.com/problems/count-the-number-of-good-subarrays/?envType=daily-question&envId=2025-04-16*/

#include<bits/stdc++.h>
class Solution {
    public:
    long long countGood(std::vector<int>& nums, int k) {
        int n = nums.size();
        int same = 0, right = -1;
        std::unordered_map<int, int> mMap;
        long long ans = 0;
        for (int left = 0; left < n; ++left) {
            while (same < k && right + 1 < n) {
                ++right;
                same += mMap[nums[right]];
                ++mMap[nums[right]];
            }
            if (same >= k) {
                ans += n - right;
            }
            --mMap[nums[left]];
            same -= mMap[nums[left]];
        }
        return ans;
    }
};
int main() {
    Solution s1;
    std::vector<int> num = {3,1,4,3,2,2,4};
    int k =2;
    int result = s1.countGood(num,k);
    std::cout<<result;
}