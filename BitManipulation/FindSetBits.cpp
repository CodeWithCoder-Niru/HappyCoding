/**
 * Find Set Bits in an Integer
 * Given an integer, find the number of set bits in it.
 * A set bit is a bit that has a value of 1.
 * Example:
 * Input: n = 5
 * Output: 2
 * Explanation: The binary representation of 5 is 101, which has 2 set bits.
 * Input: n = 7
 * Output: 3
 * Explanation: The binary representation of 7 is 111, which has 3 set bits
 * 


 */


#include <bits/stdc++.h>



int main() {

    int x = 7; int cnt =0 , y =1;

    while(x) {
        int set = x%2;
        if(set) 
            cnt++;
        x = x/2;
    }
    std::cout <<cnt;

    // while(x) {

    //     if(x & 1)
    //         cnt++;
    //     x =x >> 1;
    // }
    // std::cout <<cnt;
}