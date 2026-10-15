/*https://leetcode.com/problems/majority-element/*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto n = nums.size();
        return nums[n/2];
        
    }
};

int main()
{
    Solution S1;
    vector<int>result = {2,2,1,1,1,2,2};
    auto N = S1.majorityElement(result);
    cout<<N;
}