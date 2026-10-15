//https://leetcode.com/problems/find-the-largest-almost-missing-integer/description/?envType=daily-question&envId=2026-08-18

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        std::unordered_map<int, int> freq;
        int l = 0;
        while(l < nums.size()){
            for(int i=l; i<k ;i++){
                freq[nums[i]]++;
            }
            l++;
        }

        return 0;
        
    }
};

int main(){
    std::vector<int> num{3,9,2,1,7};
    std::cout<< largestInteger(num);
}