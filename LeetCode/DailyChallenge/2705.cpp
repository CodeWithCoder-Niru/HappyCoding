/*https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/?envType=daily-question&envId=2025-05-27*/
#include<bits/stdc++.h>
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int itr = 1, sum = 0; 
        while(itr <= n) {
            if(itr % m == 0) {
                sum -= itr;
            }
            else {
                sum += itr;
            }
            itr++;
        }
        return sum;
    }
};

int main() {
    Solution S1;
    int diff{S1.differenceOfSums(5, 1)};
    std::cout<< "Difference :" << diff;
}