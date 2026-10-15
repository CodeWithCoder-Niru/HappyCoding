/*https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/?envType=daily-question&envId=2025-05-16*/
#include<bits/stdc++.h>
class Solution {
public:
    std::vector<std::string> getWordsInLongestSubsequence(std::vector<std::string>& words, std::vector<int>& groups) {
        std::vector<std::string> result;
        int last = -1;
        for (int i = 0; i < words.size(); ++i) {
            bool isOk = true;
            for (size_t j = 0; j < words[i].size() - 1; ++j) {
                if (words[i][j] == words[i][j + 1]) {
                    isOk = false;
                    std::cout << "isOk::" << isOk << std::endl;
                    break;
                }
            }
            if ((groups[i] != last) && (isOk)) {
                result.push_back(words[i]);
                last = groups[i];
            }
        }
        return result;
    }
};

int main(){
    Solution S1;
    std::vector<std::string>words{"baa","ada"};
    std::vector<int> groups{1,2};
    std::vector<std::string>result{S1.getWordsInLongestSubsequence(words,groups)};
    for(auto const &itr:result) {
        std::cout<< itr ;
    }
}