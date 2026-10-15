/**
 * 
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/?envType=problem-list-v2&envId=array
 */


#include<bits/stdc++.h>

class Solution {
public:
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int need = target + prefix[i];

            auto it = lower_bound(prefix.begin(), prefix.end(), need);

            if (it != prefix.end()) {
                int j = it - prefix.begin();
                ans = min(ans, j - i);
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
};

int main() {
    Solution S1;

    int targrt = 2;
    std::vector<int>num{};
    int result = S1.minSubArrayLen(targrt, num);
    std::cout <<result;
}