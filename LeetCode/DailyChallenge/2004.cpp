/*https://leetcode.com/problems/rabbits-in-forest/description/?envType=daily-question&envId=2025-04-20*/
#include<bits/stdc++.h>
#include<cmath>

class Solution {
    public:
        int numRabbits(std::vector<int>& answers) {
            std::unordered_map<int, int> count;
            for (int ans : answers) {
                count[ans]++;
            }
            int total = 0;
            for (auto& [x, freq] : count) {
                int group_size = x + 1;
                int groups = (freq + group_size - 1) / group_size;
                total += groups * group_size;
            }
            return total;
        }
};

int main() {
    Solution s1;
    std::vector<int> nums = {10,10,10};
    long long result = s1.numRabbits(nums);
    std::cout<<"Result:"<<result;
}