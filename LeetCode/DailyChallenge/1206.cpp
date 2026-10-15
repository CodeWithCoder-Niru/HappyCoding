/*https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/?envType=daily-question&envId=2025-06-12*/
#include<bits/stdc++.h>
class Solution {
public:
    int maxAdjacentDistance(std::vector<int>& nums) {
        int max=0;
        for(auto i=0;i<nums.size();i++){
            if(i != nums.size()-1){
                int max1 = abs(nums[i] - nums[i+1]);
                if(max1 > max) {
                    max=max1;
                } 
            }
            else {
                int max2 = abs(nums[i] - nums[0]);
                if(max2 > max) {
                    max=max2;
                } 
            }
        }
        return max;
    }
};

int main(){
    Solution S1;
    std::vector<int>nums{-5,-10,-5};
    int Result = S1.maxAdjacentDistance(nums);
    std::cout<<"RESULT : "<< Result;
}