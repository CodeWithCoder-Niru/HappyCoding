/*https://leetcode.com/problems/count-subarrays-with-score-less-than-k/?envType=daily-question&envId=2025-04-28*/
#include<bits/stdc++.h>
class Solution {
    public:
        long long countSubarrays(std::vector<int>& nums, long long k) {
            long long n = nums.size();
            long long cnt = 0;
            long long sum = 0;
            for(auto i=0 ; i<n ; i++) {
                if(nums[i] < k) {
                    cnt++;
                    sum = nums[i];
                    for(auto j=i+1 ; j<n ; j++) {
                        sum += nums[j];
                        std::cout<<"sum is :" << sum << std::endl; 
                        if(sum * (j-i+1) < k) {
                            cnt++;
                        }
                    }
                    sum = 0;
                }
            }
        return cnt;
    }
};

int main() {
    Solution S1;
    std::vector<int> nums ={4,3,5};
    long long Result{S1.countSubarrays(nums, 11)};
    std::cout<<Result<<std::endl;
}

/*Time complexity O(n)*/
/*class Solution {
    public:
        long long countSubarrays(std::vector<int>& nums, long long k) {
            int n = nums.size(), start = 0;
            long long currSum = 0LL, score = 0LL, result = 0LL;
            for(int end = 0; end < n; end++) {
                long long length = end - start + 1;
                currSum += nums[end];
                score = (currSum * length);
                while(start <= end && score >= k) {
                    currSum -= nums[start];
                    start += 1;
                    length = end - start + 1;
                    score = currSum * length;
                }
                //result += (1LL * ((length + 1) * length) / 2) - (1LL * ((length - 1) * length) / 2);
                result += end - start + 1;
            }
            return result;
        }
    };*/