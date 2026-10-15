/*https://leetcode.com/problems/permutation-difference-between-two-strings/description/*/
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        auto n= s.length();int i =0, Result = 0;
        auto n2=t.length();
        while(i<n)
        {
            for(auto j=0;j<n2;j++)
            {
                if(s[i] == t[j])
                {
                    Result += fabs(i-j);
                }
            }
             i++; 
        }
        return Result;
    }
};

int main()
{
    Solution S1;
    std::string s("abcde");
    std::string t("edbac");
    int a = S1.findPermutationDifference(s,t);
    cout<<a;
}