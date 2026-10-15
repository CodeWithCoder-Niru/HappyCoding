/*https://leetcode.com/problems/sort-colors/submissions/1636590761/?envType=daily-question&envId=2025-05-17*/
#include<bits/stdc++.h>
class Solution {
public:
    std::vector<int> sortColors(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return nums;
        
    }
};

int main(){
    Solution S1;
    std::vector<int>nums={6,2,9};
    std::vector<int>res=S1.sortColors(nums);
    for(int i=0;i<res.size();i++){
        std::cout<<res[i];
    }
   
}