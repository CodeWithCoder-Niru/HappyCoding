/**https://leetcode.com/problems/is-subsequence/description/ */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sp = 0;
        int tp = 0;
        while(sp < s.length() && tp < t.length()){
            if(s[sp] == t[tp])
                sp++;
            
            tp++;
        }

        if(sp == s.size())
            return true;
        else
            return false;
        
    }
};

int main() {
    
    Solution s;
    std::string str1{"abc"};
    std::string str2{"ahbgdc"};
    std::cout<<s.isSubsequence(str1, str2);
    return 0;
}