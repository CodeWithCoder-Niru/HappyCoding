/**https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/ */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minValue = INT_MAX;

        for(auto itr:prices){
            minValue = std::min(minValue, itr);
            maxProfit = std::max(maxProfit, itr-minValue);
        }

        return maxProfit;
    }
};

int main() {
    
    Solution s;
    std::vector<int> prices{7,1,5,3,6,4};
    std::cout<<s.maxProfit(prices);
    return 0;
}