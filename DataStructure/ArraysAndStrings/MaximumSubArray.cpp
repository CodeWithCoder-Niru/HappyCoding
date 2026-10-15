#include<bits/stdc++.h>
using namespace std;

vector<int> maxSubArray(vector<int>& nums) {
    int currentSum = nums[0];
    int maxSum = nums[0];

    int start = 0, end = 0;
    int tempStart = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > currentSum + nums[i]) {
            currentSum = nums[i];
            tempStart = i;  // start new subarray
        } else {
            currentSum += nums[i];
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }
    }

    // Extract subarray
    vector<int> result;
    for (int i = start; i <= end; i++) {
        result.push_back(nums[i]);
    }

    return result;
}