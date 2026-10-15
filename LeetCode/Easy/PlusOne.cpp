#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto value = 1;
        for(auto i=0;i<digits.size();i++)
        {
            
            if(i == digits.size()-1)
            {
                auto sum = digits.back()+1;
                    digits[i] = sum%10;
                if(sum < 10)
                {
                    value = 0;
                    break;
                }
            }
            
        }
        if (value > 0)
        {
            digits.insert(digits.begin(),value);
        }
        return digits;
        
    }
};

int main()
{
    Solution S1;
    vector<int>result = {9,9};
    vector<int>result1 = S1.plusOne(result);
    for(auto i:result1)
    {
        cout<<i;
    }
}


/*
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer.
The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.
Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
*/