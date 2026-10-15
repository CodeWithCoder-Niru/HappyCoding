#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        sort(height.begin(), height.end());
        int size = height.size();
        int max_height = height.at(size-1);
        for(auto i=size ; i>0  ; i--)
        {
            if(height[i-1] < max_height )
                return height.at(i-1)*height.at(i-1);
        }
        return 0;
    }

};

int main() {
    Solution S1;
    vector<int>result = {1,1};
    int height = S1.maxArea(result);
    cout<<height;
}
