/*https://leetcode.com/problems/minimum-distance-to-the-target-element/description/?envType=daily-question&envId=2026-04-13*/


#include<bits/stdc++.h>

class Solution {
public:
    int getMinDistance(std::vector<int>& nums, int target, int start) {
        int i = 0;
        res = nums.size();
        while(i < nums.size()) {

            if(nums[i] == target) {
                res = std::min(min, abs(i - start));
            }
            i++;
        }
        return res;
    }
};

int main() {
    Solution S1;
    std::vector<int> num{1,1,1,1,1,1,1,1,1};
    int result = S1.getMinDistance(num, 1, 0);
    std::cout<<result;
    return 0;
}