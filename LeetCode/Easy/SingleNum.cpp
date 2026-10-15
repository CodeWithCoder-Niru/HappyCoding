/*https://leetcode.com/problems/single-number/*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l = nums.size();
        //int res = nums[l-1];
        auto i =0;
        while(i < l -2)
        {
            if(nums[i] == nums[i+1])
                i = i+2;
            else
                return nums[i];
        }
        return nums[i];
    }

    /*Other method
    int result =0;
    for(auto num:nums)
    {
        result^=num;
    }
    return result;
    
    */
};

int main()
{
    Solution S1;
    vector<int>result = {4,1,2,1,2};
    auto N = S1.singleNumber(result);
    cout<<N;
}