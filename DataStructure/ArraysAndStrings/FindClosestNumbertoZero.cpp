
/**https://leetcode.com/problems/find-closest-number-to-zero/ */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findClosestNumber(vector<int>& nums) {

        int closeNum = INT_MAX;

        for(auto itr:nums){
            closeNum = std::min(closeNum, std::abs(itr));
        }

        auto it = std::find(nums.begin(), nums.end(), closeNum);
        if(it != nums.cend())
            return closeNum;
        else {
            return closeNum*(-1);
        }
        
    }
};

int main(){
    
    Solution s;
    std::vector<int> nums{-4,-2,1,4,8};
    std::cout<<s.findClosestNumber(nums);
    return 0;
}