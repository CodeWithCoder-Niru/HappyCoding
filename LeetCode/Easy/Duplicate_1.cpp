/*https://leetcode.com/problems/contains-duplicate/*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        auto n=nums.size();
        auto cnt=0,k=0;
        while(k<n)
        {
            for(auto i=0;i<n;i++)
            {
                if(nums[k] == nums[i])
                {
                    cnt++;
                }
            }
            k++;
        }
        if(cnt > n)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
/*
std::set<int> fset;
    int i = 0;
    while(i < nums.size()) {
        if(fset.find(nums[i]) != fset.end()) {
            return true;
        }
        fset.insert(nums[i]);
        i++;
    }
    return false;
*/
int main()
{
    Solution S1;
    vector<int>result = {1,2,3,4};
    bool N = S1.containsDuplicate(result);
    cout<<N;
}