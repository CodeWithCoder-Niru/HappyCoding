/*https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/description/?envType=daily-question&envId=2025-06-14*/
#include<bits/stdc++.h>
class Solution {
public:
    int minMaxDifference(int num) {
        int max = num; int min = 0;
        int per = num % 10;
        if((per != 9) && (per)){

        }
        std::cout<< per;
        return 0;
    }
};

int main(){
    Solution S1;
    int Result = S1.minMaxDifference(11891);
    std::cout<< "RESULT:" <<Result;
}