/*https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/?envType=daily-question&envId=2025-04-24*/
#include<bits/stdc++.h>

int countCompleteSubarrays(std::vector<int>& nums) {
    int n = nums.size();
    // Step 1: Count total distinct elements in nums
    std::unordered_set<int> totalDistinctSet(nums.begin(), nums.end());
    int totalDistinct = totalDistinctSet.size();
    int result = 0;
    // Step 2: Loop through all subarrays
    for (int i = 0; i < n; ++i) {
        std::unordered_set<int> seen;
        for (int j = i; j < n; ++j) {
            seen.insert(nums[j]);
            if (seen.size() == totalDistinct) {
                result++;
            }
        }
    }
    return result;
}

int main() {
    std::vector<int> nums1 = {1, 3, 1, 2, 2};
    std::vector<int> nums2 = {5, 5, 5, 5};

    std::cout << "Example 1: " << countCompleteSubarrays(nums1) << std::endl;
    std::cout << "Example 2: " << countCompleteSubarrays(nums2) << std::endl;
    return 0;
}