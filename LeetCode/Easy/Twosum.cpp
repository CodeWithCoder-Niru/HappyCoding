#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {

        for(auto i=nums.begin(); i!=nums.end(); i++)
        {
            for(auto j=i+1; j!=nums.end();j++)
            {
                if(*i+*j == target)
                {
                    return {static_cast<int>(i-nums.begin()), static_cast<int>(j-nums.begin())};
                }
            }
        }
        return {};
    }
};

int main()
{
    Solution s1;
    vector<int> nums = {2,7,11,15};
    vector<int> result = s1.twoSum(nums, 9);

    for(int index : result ){
        cout<<index<<" ";
    }
    return 0;
}