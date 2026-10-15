/*https://leetcode.com/problems/type-of-triangle/?envType=daily-question&envId=2025-05-19*/
#include<bits/stdc++.h>
class Solution {
public:
    std::string triangleType(std::vector<int>& nums) {
        if((nums[0] == nums[1]) && (nums[1] == nums[2])) {
            return "equilateral";
        }
        else if((nums[0] == nums[1]) || (nums[1] == nums[2]) || (nums[2] == nums[0])) {
            return "isosceles";
        }
        else {
            if((nums[0]+nums[1]<nums[2]) || ((nums[1]+nums[2])<nums[0]) || ((nums[2]+nums[0])<nums[1])) {
                return "none";
            }
            else {
                return "scalene";
            }
        }
    }
};

int main() {
    Solution S1;
    std::vector<int> nums{8,4,4};
    std::string str = S1.triangleType(nums);
    std::cout<< "RESULT: " << str;
}