/*https://leetcode.com/problems/take-gifts-from-the-richest-pile/?envType=daily-question&envId=2025-04-21*/
#include<bits/stdc++.h>
class Solution {
    public:
        long long pickGifts(std::vector<int>& gifts, int k) {
            auto itr = 1;
            long long size = gifts.size();
            long long sum =0;
            while(itr <= k) {
                std::sort(gifts.begin(), gifts.end());
                gifts[size-1] = std::sqrt(gifts[size-1]);
                itr++;
            }
            for(auto &i:gifts) {
                sum+=i;
            }
            return sum;
        }
};
int main() {
    Solution S1;
    std::vector<int> diff = {25,64,9,4,100};
    long long Result = S1.pickGifts(diff, 4);
    std::cout<<"RESULT: " << Result;
}