/*https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/?envType=daily-question&envId=2025-06-10*/
#include<bits/stdc++.h>
class Solution {
public:
    int maxDifference(std::string s) {
        std::set<int>mTable;
        for(auto const &itr:s) {
            int value = std::count(s.begin(), s.end(), itr);
            mTable.insert(value);
        }
        int max_element = *mTable.rbegin();
        int second_max_element = *std::next(mTable.rbegin());
        return max_element - second_max_element;
    }
};
int main() {
    Solution S1;
    int result = S1.maxDifference("aaaaabbc");
    std::cout<< result;
}