/*https://leetcode.com/problems/final-value-of-variable-after-performing-operations/?envType=daily-question&envId=2025-10-20*/
#include<bits/stdc++.h>
class Solution {
public:
    int finalValueAfterOperations(std::vector<std::string>& operations) {
        int x = 0;
        while(!operations.empty()) {
            std::string op = operations.back();
            operations.pop_back();
            if(op[1] == '+') {
                x++;
            } else {
                x--;
            }
        }
        return x;
    }
};
int main() {
    Solution S1;
    std::vector<std::string> diff = {"--X","X++","X++"};
    int Result = S1.finalValueAfterOperations(diff);
    std::cout<<"RESULT: " << Result;
}