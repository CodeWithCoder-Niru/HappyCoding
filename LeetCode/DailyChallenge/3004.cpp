/*https://leetcode.com/problems/find-numbers-with-even-number-of-digits/?envType=daily-question&envId=2025-04-30*/
#include<bits/stdc++.h>

class Solution {
    public:
        int findNumbers(std::vector<int>& nums) {
            int cnt = 0;
            for(auto i:nums) {
                int numDigits = (i == 0) ? 1 : static_cast<int>(log10(i)) + 1;
                if(numDigits%2 == 0) {
                    cnt++;
                }
            }
        return cnt;
    }
};

int main() {
    Solution S1;
    std::vector<int> nums = {12,345,2,6,7896};
    int result = S1.findNumbers(nums);
    std::cout<<result<<std::endl;
}

