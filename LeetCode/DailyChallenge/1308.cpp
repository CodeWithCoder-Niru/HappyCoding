//https://leetcode.com/problems/longest-substring-of-one-repeating-character/submissions/2105357909/?envType=daily-question&envId=2026-08-13
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        std::unordered_map<char, int> freq;
        std::
        int maxlen = 0;
        std::vector<int> result;

        for(auto itr:s){
            freq[itr]++;
        }

        for(int i=0; i <queryIndices.size(); i++){
            s.at(queryIndices[i]) = queryCharacters[i];
            freq[queryCharacters[i]]++;

            int l =0 , r = 0;
            while(r < s.size()){
                
            }
            result.push_back(maxlen);
        }
        return result;
        
    }
};
int main(){
    Solution S1;
    std::string s{"dbgmcagale"};
    std::string queryStr{"mf"};
    std::vector<int> queryIndex{5, 0};
    std::vector<int> result{S1.longestRepeating(s, queryStr, queryIndex)};

    for(auto itr: result){
        std::cout<< itr <<" ";
    }

    return 0;

}