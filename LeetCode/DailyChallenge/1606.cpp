/*https://leetcode.com/problems/maximum-difference-between-increasing-elements/solutions/?envType=daily-question&envId=2025-06-16*/
#include<bits/stdc++.h>
class Solution {
public:
    int maximumDifference(std::vector<int>& nums) {
        int result = -1;
        for(auto i=0;i<nums.size()-1; i++) {
            if(nums[i]<nums[i+1]){
                result= nums[i+1] - nums[i];
            }
        }
        return result;
    }
};

int main(){
    Solution S1;
    std::vector<int>num{1,5,2,10};
    int RESULT = S1.maximumDifference(num);
    std::cout<<"Result: " << RESULT;
}