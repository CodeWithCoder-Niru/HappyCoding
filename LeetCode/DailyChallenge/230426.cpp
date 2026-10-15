/**https://leetcode.com/problems/sum-of-distances/?envType=daily-question&envId=2026-04-23 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {

        std::vector<long long> result;
        int n = nums.size();
        for(int i=0; i <n ; i++) {
            int l=0, r=n-1;
            int value = 0;
            while(l <= r){
                if(nums[i] == nums[l] && i != l){
                    value = value + abs(i - l);
                }
                if(nums[i] == nums[r] && i != r && r != l) {
                    value = value + abs(i - r);
                }
                l++;
                r--;
            }
            result.push_back(value);

        }
        return result;
        
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 1, 1, 2};
    vector<long long> result = sol.distance(nums);
    for (long long val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}