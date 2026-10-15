/**
https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2026-03-08
*/


#include<bits/stdc++.h>

class Solution {
public:
    std::string findDifferentBinaryString(std::vector<std::string>& nums) {
        int n = nums.front().size();
        int total = pow(2, n);

        for (int i = 0; i < total; i++) {
            std::bitset<32> b(i);                 // convert number to binary
            std::string s = b.to_string();
            std::cout << s.substr(32 - n) << std::endl; // print last n bits

            auto itr = std::find(nums.begin(), nums.end(), s.substr(32 - n));
            if(itr == nums.end()) {
                return s.substr(32 - n);
                break;
            }
        }
        return "";
        
    }
};

int main() {
    Solution s1;
    std::vector<std::string> nums{"111","011","001"};
    std::string final = s1.findDifferentBinaryString(nums);
    std::cout << final;

    return 0;
}