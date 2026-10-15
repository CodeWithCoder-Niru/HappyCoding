/*https://leetcode.com/problems/find-words-containing-character/description/?envType=daily-question&envId=2025-05-24*/
#include<bits/stdc++.h>
class Solution {
public:
    std::vector<int> findWordsContaining(std::vector<std::string>& words, char x) {
        std::vector<int> result;
        for(auto i=0;i<words.size();i++) {
            auto find = words[i].find(x);
            if(find != std::string::npos) {
                result.emplace_back(i);
            }
        }
        return result;
    }
};

int main() {
    Solution S1;
    std::vector<std::string> words{"leet","code"};
    char x = 'e';
    std::vector<int> RESULT = S1.findWordsContaining(words, x);
    for(auto const &itr:RESULT){
        std::cout<< itr ;
    }
}