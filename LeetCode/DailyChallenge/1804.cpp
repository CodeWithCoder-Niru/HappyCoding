/*https://leetcode.com/problems/count-and-say/description/?envType=daily-question&envId=2025-04-18*/
#include<bits/stdc++.h>
class Solution {
public:
    std::string countAndSay(int n) {
        int last = 1;
        std::string str;
        std::string result;
        static std::string final = "";
        int cnt;

        while(last <= n) {
            if(last == 1) {
                str.append(std::to_string(last));
                result = str;
            }
            else {
                result = "";
                for(auto i=0; i<str.size(); i++){
                    int count = 1;
                    while(i+1 < str.size() && str[i] == str[i+1]) {
                        count++;
                        i++;
                    }
                    result += std::to_string(count) + str[i];
                }
                if(last == n) {
                    final.append(result); 
                }
                str = result;
            }
            last++;
        }
        return result;
    }
};

int main() {
    Solution s1;
    std::string result = s1.countAndSay(4);
    std::cout<<"Result:"<<result;
}
