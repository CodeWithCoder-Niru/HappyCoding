/*https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/description/?envType=daily-question&envId=2025-05-10*/
#include<bits/stdc++.h>
class Solution {
public:
    long long minSum(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        long long count1 = std::count(nums1.begin(), nums1.end(), 0);
        long long count2 = std::count(nums2.begin(), nums2.end(), 0);
        int sum1 = std::accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = std::accumulate(nums2.begin(), nums2.end(), 0);
        if(count1 == 0 || count2 == 0 && (sum1 != sum2)) {
            return -1;
            exit;
        }
        if((sum1 == sum2)){
            if(count1>count2) {
                sum1+=count1;
            }
            else {
                sum1+=count2;
            }
            return sum1;
        }
        else if(sum1 > sum2) {
            sum1+=count1;
            return sum1;
        }
        else {
            sum2+=count2;
            return sum2;
        }
    }
};
int main(){
    Solution S1;
    std::vector<int>num1{0,17,20,17,5,0,14,19,7,8,16,18,6};
    std::vector<int>num2{21,1,27,19,2,2,24,21,16,1,13,27,8,5,3,11,13,7,29,7};
    long long result{S1.minSum(num1, num2)};
    std::cout<< "RESULT :" << result;
}