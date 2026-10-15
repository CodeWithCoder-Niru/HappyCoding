/*https://leetcode.com/problems/total-characters-in-string-after-transformations-i/description/?envType=daily-question&envId=2025-05-13*/
#include<bits/stdc++.h>
class Solution {
public:
    int lengthAfterTransformations(std::string s, int t) {
        int itr = 1;
        std::string str{""};
        while(itr <= t) {
            for(auto i:s) {
                if('z' == i) {
                    str += "ab";
                }
                else {
                    int ascii = static_cast<int>(i);
                    // std::cout<<
                    char ch = static_cast<char>(ascii+1);
                    str += ch;
                }
            }
            s = str;
            str = "";
            itr++;
        }
        return s.length();
    }
};

int main() {
    Solution S1;
    int result = S1.lengthAfterTransformations("jqktcurgdvlibczdsvnsg", 2);
    std::cout<< "RESULT:" << result;

}