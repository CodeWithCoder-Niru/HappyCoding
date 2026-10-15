
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
    int n = arr.size();
    int targetFrequency = n / 4;
    for (int i = 0; i < n - targetFrequency; ++i) {
        if (arr[i] == arr[i + targetFrequency]) {
            return arr[i];
        }
    }
    return arr[n - 1];
    }
};

int main()
{
    Solution S1;
    vector<int>result = {1,2,2,6,6,6,6,7,10};
    auto N = S1.findSpecialInteger(result);
    cout<<N; //6
}