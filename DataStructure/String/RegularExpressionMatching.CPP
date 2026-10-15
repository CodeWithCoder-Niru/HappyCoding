/*https://leetcode.com/problems/regular-expression-matching/description/*/

#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        for (int i = 1; i <= m; ++i) {

int main() {
    Solution sol;
    string s = "aa", p = "a";
    cout << sol.isMatch(s, p) << endl; // Output: false
    s = "aa", p = "a*";
    cout << sol.isMatch(s, p) << endl; // Output: true
    s = "ab", p = ".*";
    cout << sol.isMatch(s, p) << endl; // Output: true
    return 0;
}