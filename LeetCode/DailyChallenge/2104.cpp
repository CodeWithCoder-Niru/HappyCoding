/*https://leetcode.com/problems/count-the-hidden-sequences/description/?envType=daily-question&envId=2025-04-21*/
#include<bits/stdc++.h>
class Solution {
    public:
        int numberOfArrays(std::vector<int>& differences, int lower, int upper) {
            long long l = lower;
            long long r = upper;
            long long ResultDiff = 0;
            for(int i = 0; i< differences.size(); i++){
                ResultDiff += differences[i];
                l= std::max(l, lower-ResultDiff);
                r = std::min(r, upper-ResultDiff);
            }
            int count = (int)(r-l+1);
            return count < 0 ? 0 : count;
        }
};
int main() {
    Solution S1;
    std::vector<int> diff = {1, -3, 4};
    int Result = S1.numberOfArrays(diff, 1, 6);
    std::cout<<"RESULT: " << Result;
}

/*
For example, given differences = [1, -3, 4], lower = 1, upper = 6, the hidden sequence is a sequence of length 4 whose elements are in between 1 and 6 (inclusive).
[3, 4, 1, 5] and [4, 5, 2, 6] are possible hidden sequences.
[5, 6, 3, 7] is not possible since it contains an element greater than 6.
[1, 2, 3, 4] is not possible since the differences are not correct.
*/