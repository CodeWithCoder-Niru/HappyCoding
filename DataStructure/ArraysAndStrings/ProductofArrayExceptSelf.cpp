/**https://leetcode.com/problems/product-of-array-except-self/description/ */

#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         std::vector<int> result ;

//         int i = 0 ;
//         int prod = 1;
//         while(i < nums.size()) {

//             for(int j=0 ; j<nums.size() ; j++){

//                 if(i == j)
//                     continue;

//                 prod *=nums[j];
//             }
//             result.push_back(prod);
//             prod =1;
//             i++;
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        std::vector<int> result(n, 1);

        // Step 1: Left products
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            result[i] = prefix;
            prefix *= nums[i];
        }

        // Step 2: Right products
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= suffix;
            suffix *= nums[i];
        }
        return result;
    }
};

int main() {
    
    Solution s;
    std::vector<int> nums{1,2,3,4};
    std::vector<int> result = s.productExceptSelf(nums);
    for(auto itr:result)
        std::cout<<itr<<" ";
    return 0;
}