/**https://leetcode.com/problems/reverse-integer/ */

#include <bits/stdc++.h>

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0; 
            rev = rev * 10 + pop;
        }
        return rev;
    }
};


int main() {
    Solution sol;
    int x = 123;
    std::cout << sol.reverse(x) << std::endl; // Output: 321
    x = -123;
    std::cout << sol.reverse(x) << std::endl; // Output: -321
    x = 120;
    std::cout << sol.reverse(x) << std::endl; // Output: 21
    return 0;
}