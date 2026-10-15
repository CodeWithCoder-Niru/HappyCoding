/**
Given an array nums with n objects colored red, white, or blue,
sort them in-place so that objects of the same color are adjacent,
with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
 */

#include<bits/stdc++.h>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while(mid <= high){
            if(nums[mid] == 0){
                std::swap(nums[mid], nums[low]);
                mid++;
                low++;
            }else if(nums[mid] == 1){
                mid++;
            }
            else{
                std::swap(nums[mid], nums[high--]);
            }
        }
    }
};

int main(){
    Solution s1;
    std::vector<int>nums{2,0,2,1,1,0};
    s1.sortColors(nums);
}
