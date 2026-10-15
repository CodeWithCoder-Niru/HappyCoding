/**https://leetcode.com/problems/longest-common-prefix/description/ */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            std::string commonStr{strs[0]};
            if(strs.empty())
                return "";

            int minlength = INT_MAX;

            for(auto itr : strs) {
                minlength = std::min(minlength, (int)itr.length());
            }
            
            int i = 0;
            while(i < minlength) {
                for(auto it:strs) {
                    if(it[i] != commonStr[i]){
                        return commonStr.substr(0, i);
                    }
                }
                i++;
            }
            return commonStr.substr(0,i);
        }
};

int main(){
    
    Solution s;
    std::vector<std::string> strs{"flower","flow","flight"};
    std::cout<<s.longestCommonPrefix(strs);
    return 0;
}