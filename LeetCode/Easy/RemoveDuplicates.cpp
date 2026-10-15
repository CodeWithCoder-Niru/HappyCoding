#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto k=1;
        for(auto i=1; i<nums.size(); i++)
        {
            if(nums[i] != nums [i-1])
            {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};


int main()
{
    Solution S1;
    vector<int>result = {0,0,1,1,1,2,2,3,3,4};
    int k = S1.removeDuplicates(result);
    cout<<k;
}