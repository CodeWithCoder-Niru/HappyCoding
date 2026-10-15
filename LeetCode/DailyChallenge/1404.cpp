/*https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/?envType=daily-question&envId=2024-05-29*/
#include<iostream>
#include<string>

using namespace std;
class Solution {
public:
    int numSteps(string s) {
        auto count=0;
        uint64_t decimal = std::stoull(s, nullptr, 2);
        while(decimal != 1)
        {
            if(decimal % 2 == 0)
            {
                decimal = decimal/2;
                count++;
            }
            else
            {
                decimal = decimal+1;
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution S1;
    string s("100100001010010101101000111100100111101111000111111010010001100001000100011001");
    int a = S1.numSteps(s);
    cout<<a;
}