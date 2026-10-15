/*https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/?envType=daily-question&envId=2026-04-17*/


#include <bits/stdc++.h>
using namespace std;
class Solution {

public:
    int reverseNumber(int num) {
        int reversed = 0;
        while (num > 0) {
            reversed = reversed * 10 + num % 10;
            num /= 10;
        }
        return reversed;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        std::unordered_map<int, int> mMap;
        int minValue = INT_MAX;

        for(int i=0; i<nums.size(); i++) {
            if(mMap.find(nums[i]) != mMap.end()) {
                minValue = std::min(minValue, i - mMap[nums[i]]);
            }
            mMap[reverseNumber(nums[i])] = i;
        }
        return minValue == INT_MAX ? -1 : minValue;;
        
    }
};

int main() {
    Solution S1;
    std::vector<int> num{120,21};
    std::cout << S1.minMirrorPairDistance(num);

}