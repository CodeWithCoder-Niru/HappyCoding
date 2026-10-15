#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //merge the vectors
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
            //auto med = 0.0f;
            if(nums1.size()%2 == 0)
            {
                int var_even = nums1.size()/2;
                int var_even_1 = var_even -1;
                return (nums1.at(var_even)+nums1.at(var_even_1))/2.0;
            }
            else
            {
                int var_odd = nums1.size()/2;
                return nums1.at(var_odd);
            }
        return 0;
        
    }
};

int main()
{
    Solution S1;
    vector<int>num1 = {1,2};
    vector<int>num2 = {3,4};
    double median = S1.findMedianSortedArrays(num1, num2);
    cout<<median;
}

// Merge vec2 into vec1 using insert
// vec1.insert(vec1.end(), vec2.begin(), vec2.end());
// Merge vec1 and vec2 into merged using std::merge
// std::merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), merged.begin());
// Merge vec2 into vec1 using std::copy
// std::copy(vec2.begin(), vec2.end(), std::back_inserter(vec1));