/*https://leetcode.com/problems/words-within-two-edits-of-dictionary/description/?envType=daily-question&envId=2026-04-22*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    std::vector<string> twoEditWords(std::vector<string>& queries, std::vector<string>& dictionary) {
        vector<string> result;

        for(auto i=0; i<queries.size(); i++) {
            std::string str{queries[i]};

            for(auto j=0;j<dictionary.size();j++) {
                int l=0, r=0;
                int cnt = 0;
                std::string dest{dictionary[j]};
                while(l < str.size()) {
                    if(str[l] != dest[l]){
                        cnt++;
                        if(cnt > 2){
                            break;
                        }
                    }
                    l++;
                    // r++;
                }
                if(cnt <= 2) {
                    result.push_back(str);
                    break;
                }
            }
        }
        return result;

        
    }
};

int main() {
    Solution sol;
    vector<string> queries = {"word","note","ants","wood"};
    vector<string> dictionary = {"wood","joke","moat"};
    vector<string> result = sol.twoEditWords(queries, dictionary);
    for (const auto& word : result) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    return 0;
}

