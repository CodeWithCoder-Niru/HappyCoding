/*https://leetcode.com/problems/score-of-a-string/description/*/
#include <iostream>
#include <string.h>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0,i=0;
        while(i<s.length()-1)
        {
            auto ASCII_Value = static_cast<int>(s[i]);
            auto ASCII_Value_2 = static_cast<int>(s[i+1]);
            sum=sum+abs(ASCII_Value - ASCII_Value_2);
            i++;
        }
        return sum;
    }
};

int main()
{
    Solution S1;
    string s("zaz");
    int a = S1.scoreOfString(s);
    cout<<a;
}