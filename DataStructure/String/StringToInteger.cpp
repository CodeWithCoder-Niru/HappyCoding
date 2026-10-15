/**
 * https://leetcode.com/problems/string-to-integer-atoi/description/
 */

#include <bits/stdc++.h>

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size(), sign = 1;
        long long result = 0;

        // Skip leading whitespaces
        while (i < n && s[i] == ' ') { //what we
            i++;
        }

        // Check for optional sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Convert digits to integer
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            result = result * 10 + digit; //
            i++;
        }

        return static_cast<int>(sign * result);
    }
};

int main() {
    Solution sol;
    std::string s = "   -42";
    std::cout << sol.myAtoi(s) << std::endl; // Output: -42
    s = "4193 with words";
    std::cout << sol.myAtoi(s) << std::endl; // Output: 4193
    s = "words and 987";
    std::cout << sol.myAtoi(s) << std::endl; // Output: 0
    s = "-91283472332";
    std::cout << sol.myAtoi(s) << std::endl; // Output: -2147483648 (clamped to INT_MIN)
    return 0;
}