/*https://leetcode.com/problems/count-the-number-of-special-characters-i/*/
#include <iostream>
#include <string.h>
#include <set>
#include <algorithm>
#include <cctype>  
using namespace std;

class Solution {
public:
    
    int numberOfSpecialChars(string word) {
        int count = 0;
        std::set<char> seen;
        std::string result;
        for (char ch : word) {
            if (seen.find(ch) == seen.end()) {
                seen.insert(ch);
                result += ch;
            }
        }
        for(char ch:result)
        {
            if(islower(ch))
            {
                auto upper = toupper(ch);
                auto pos = result.find(upper);
                if(pos != string::npos)
                {
                    count++;
                }
            }

        }        
        return count;
        
    }
};

int main()
{
    Solution S1;
    string s("abBCab");
    int a = S1.numberOfSpecialChars(s);
    cout<<a;
}