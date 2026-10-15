/**
 * Input:  [2, 3, -2, 4]
 * Output: 6

 * The subarray [2, 3] has the maximum product:

 * 2 × 3 = 6

 Interview Explanation

We track both the maximum and minimum products ending at each index.
The minimum is required because multiplying a negative minimum by another negative number
can produce the next maximum. At each position, we either start a new subarray
from the current element or extend one of the previous product subarrays. This gives O(n) time and O(1) space.
 */


#include<bits/stdc++.h>


int maxProduct(std::vector<int>& nums) {


    if(nums.empty())
        return 0;
    
    int currentmax = nums[0];
    int currentmin = nums[0];
    int result = nums[0];


    for(int i=1; i<nums.size(); i++){
        

        if(nums[i] < 0)
            std::swap(currentmax, currentmin);

        currentmax = std::max(currentmax, currentmax*nums[i]);

        currentmin = std::max(currentmin, currentmin*nums[i]);

        result = std::max(result, currentmax);

    }

    return result;
}

int main(){

    std::vector<int> num{-2, 0, -1};

    std::cout<< maxProduct(num);

    return 0;
}