/**https://leetcode.com/problems/roman-to-integer/description/ */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {

        std::unordered_map<char, int> roman = { {'I', 1   },
                                                {'V', 5   },
                                                {'X', 10  },
                                                {'L', 50  },
                                                {'C', 100 },
                                                {'D', 500 },
                                                {'M', 1000}};

        int sum = 0 ;
        for(int i=0; i<s.size() - 1; i++){
            if(roman[s[i]] < roman[s[i+1]] )
                sum -= roman[s[i]];
            else
                sum += roman[s[i]];
        }
        return sum + roman[s[s.size()-1]];
    }
};

int main() {
    
    Solution s;
    std::string str{"MCMXCIV"};
    std::cout<<s.romanToInt(str);
    return 0;
}