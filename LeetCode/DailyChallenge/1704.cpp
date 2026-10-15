/*https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/?envType=daily-question&envId=2025-04-17*/
#include<bits/stdc++.h>
class Solution {
    public:
        int countPairs(std::vector<int>& nums, int k) {
            int cnt = 0;
            for(auto i=0;i<nums.size();i++) {
                for(auto j=i+1;j<nums.size();j++) {
                    if((nums[i] == nums[j]) && ((i*j)%k == 0 )){
                        cnt++;
                    }
                }
            }
            return cnt;

        }
};

int main(){
    Solution s1;
    std::vector<int> num = {3,1,2,2,2,1,3};
    int k =2;
    int result = s1.countPairs(num,k);
    std::cout<<result;
}