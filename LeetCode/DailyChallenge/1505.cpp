/*https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/submissions/1634752794/?envType=daily-question&envId=2025-05-15*/
#include<bits/stdc++.h>
class Solution {
public:
    std::vector<std::string> getLongestSubsequence(std::vector<std::string>& words, std::vector<int>& groups) {
        std::vector<std::string> result;
        int last = -1;
        for (int i = 0; i < words.size(); ++i) {
            if (groups[i] != last) {
                result.push_back(words[i]);
                last = groups[i];
            }
        }
        return result;
    }
};
int main() {
    Solution S1;
    std::vector<std::string>words{"a","b","c","d"};
    std::vector<int> groups{1,0,1,1};
    std::vector<std::string>result{S1.getLongestSubsequence(words,groups)};
    for(auto const &itr:result) {
        std::cout<< itr ;
    }
}