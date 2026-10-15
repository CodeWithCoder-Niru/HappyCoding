/*https://neetcode.io/problems/top-k-elements-in-list/question?list=blind75*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int>freq;

        for(int i = 0 ; i< nums.size(); i++){
            freq[nums[i]]++;
        }

        std::vector<int> res;
        for(auto it:freq){
            if(it.second >= k)
                res.push_back(it.first);
        }
        return res;
    }
};

int main(){

    Solution s1;
    std::vector<int> num{7,7};
    std::vector<int> res= s1.topKFrequent(num, 3);
    for(auto it:res)
        std::cout<<it <<" ";

    return 0;
}
