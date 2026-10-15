/*https://leetcode.com/problems/count-largest-group/description/?envType=daily-question&envId=2025-04-23*/
#include<bits/stdc++.h>
class Solution {
    public:
        // Function to compute the digit sum of a number
        int digitSum(int num) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;  // get last digit
                num /= 10;        // remove last digit
            }
            return sum;
        }
        int countLargestGroup(int n) {
            std::unordered_map<int, int> digitSumCount;
            int maxSize = 0;

            // Step 1: Count frequency of each digit sum
            for (int i = 1; i <= n; ++i) {
                int sum = digitSum(i);
                digitSumCount[sum]++;
                maxSize = std::max(maxSize, digitSumCount[sum]);
            }
            // Step 2: Count how many groups have the max size
            int count = 0;
            for (auto& [sum, freq] : digitSumCount) {
                if (freq == maxSize) {
                    count++;
                }
            }
            return count;
        }
    };
int main() {
    Solution S1;
    std::cout << S1.countLargestGroup(13) << std::endl;
    return 0;
}
    