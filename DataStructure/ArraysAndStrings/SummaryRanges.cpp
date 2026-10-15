/**https://leetcode.com/problems/summary-ranges/description/ */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        std::vector<string> result{};
        int n = nums.size();
        int i =0;

        while(i < nums.size()) {

            int start = nums[i];
            while((i < n -1) && (nums[i+1] == nums[i] + 1)) {
                i++;
            }

            if(start != nums[i]){
                result.push_back(std::to_string(start) + "->" + std::to_string(nums[i]));
            } else {
                result.push_back(std::to_string(nums[i]));
            }
            i++;
        }
        return result;
    }
};

int main() {
    
    Solution s;
    std::vector<int> nums{0,1,2,4,5,7};
    std::vector<std::string> result = s.summaryRanges(nums);
    for(auto itr:result)
        std::cout<<itr<<" ";
    return 0;
}