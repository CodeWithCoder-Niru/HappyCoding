
#include<bits/stdc++.h>


int main() {

    std::vector<int> height{1,8,6,2,5,4,8,3,7};

    int left = 0; int right = height.size()-1;
    int ans = 0;

    while(left < right) {

        int length = std::min(height[left], height[right]);
        int width = right - left;
        ans = std::max(ans, width*length);

        if(height[left] < height[right]) 
            left++;
        else
            right--;
    }
    std::cout << ans;
    return 0;
}