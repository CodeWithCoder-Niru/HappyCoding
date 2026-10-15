/**
 * https://leetcode.com/problems/complement-of-base-10-integer/description/?envType=daily-question&envId=2026-03-11
 */


#include <bits/stdc++.h>



class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        if(n == 1) return 0;
        int ans=0;
        int cnt=0;
        while(n>0){
            if(n%2 == 0 && n/2!=0){
                ans+=pow(2, cnt);
            }
            cnt++;
            n/=2;
        }
        return ans;
    }

};


int main() {
    Solution S1;

    S1.bitwiseComplement(10);


}