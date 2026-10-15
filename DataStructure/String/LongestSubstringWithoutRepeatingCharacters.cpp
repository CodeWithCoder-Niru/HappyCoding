/**https://leetcode.com/problems/longest-substring-without-repeating-characters/description/ */

#include<bits/stdc++.h>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int left = 0;
        int maxlen = 0;
        std::unordered_set<int> seen;
        for(int right=0; right< s.size(); right++) {
            while(seen.find(s[right]) != seen.end()) {
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            maxlen = std::max(maxlen, right - left + 1);
        }
        return maxlen;
    }
};

int main() {
    Solution s1;
    std::string str{"pwwkew"};
    int result = s1.lengthOfLongestSubstring(str);
    std::cout<< result;
    return 0;

}