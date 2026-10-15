/*https://leetcode.com/problems/three-consecutive-odds/description/?envType=daily-question&envId=2025-05-11*/
#include<bits/stdc++.h>
class Solution {
public:
    bool threeConsecutiveOdds(std::vector<int>& arr) {
        int c = 0;
        for (int x : arr) {
            c = (x % 2) ? c + 1 : 0;
            if (c == 3) return true;
        }
        return false;
    }
};

int main(){
    Solution S1;
    std::vector<int>nums{1,2,34,3,4,5,7,23,12};
    bool result = S1.threeConsecutiveOdds(nums);
    std::cout<<"RESULT : " << result;
}