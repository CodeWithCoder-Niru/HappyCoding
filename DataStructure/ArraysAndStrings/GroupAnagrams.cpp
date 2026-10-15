#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(auto itr:strs){
            std::string st = itr;
            std::sort(st.begin(), st.end());
            mp[st].push_back(itr);
        }

        std::vector<std::vector<std::string>> anagram;
        for(auto it : mp){
            anagram.push_back(it.second);
        }
    }
};

int main(){
    Solution s1;

    std::vector<string> str{"act","pots","tops","cat","stop","hat"};
    s1.groupAnagrams(str);
    return 0;
}