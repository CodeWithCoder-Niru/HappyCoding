#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                
            }
        }
        
    }
};


int main()
{
    Solution S1;
    auto rows = 5;
    vector<vector<int>>result = S1.generate(rows);
    for(auto i:result)
    {
        cout<<i;
    }
}