/*https://leetcode.com/problems/valid-word/*/
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

class Solution {
public:
    bool isValid(string word) {
        bool Vowel = false;
        bool Consonant = false;
        if(word.length()<3)
        {
            return false;
        }
        for(char ch:word)
        {
            if(!isdigit(ch) && !isalpha(ch))
            {
                return false;
            }
            if(isalpha(ch))
            {
                char lowerch = tolower(ch);
                if (lowerch == 'a' || lowerch == 'e' || lowerch == 'i' || lowerch == 'o' || lowerch == 'u') {
                Vowel = true;
                } else {
                Consonant = true;
                }
            }
        }
        return Vowel&&Consonant;
    }
};

int main()
{
    Solution S1;
    string s("abcde");
    bool a = S1.isValid(s);
    cout<<a;
}