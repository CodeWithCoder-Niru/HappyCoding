#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices){

    auto buy = prices[0], max_profit = 0;
        for(auto i=1;i<prices.size();i++)
        {
            if(buy > prices[i])
                buy=prices[i];
            else if(prices[i] - buy > max_profit)
            {
                max_profit = prices[i] - buy;
            }
        }
        return max_profit;
    }
};

int main()
{
    Solution S1;
    vector<int>result = {7,1,5,3,6,4};
    auto N = S1.maxProfit(result);
    cout<<N;
}


/*https://leetcode.com/problems/best-time-to-buy-and-sell-stock/*/