/**https://leetcode.com/problems/merge-strings-alternately/description/ */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        std::string result{""};
        int l =0, r=0;

        while(l < word1.size() && r < word2.size()){
            result.push_back(word1[l]);
            result.push_back(word2[r]);
            l++;
            r++;
        }
        while(l < word1.size()){
            result.push_back(word1[l]);
            l++;
        }
        while(r < word2.size()){
            result.push_back(word2[r]);
            r++;
        }

        return result;
        
    }
};

int main() {
    
    Solution s;
    std::string word1{"abc"};
    std::string word2{"pqr"};
    std::cout<<s.mergeAlternately(word1, word2);
    return 0;
}