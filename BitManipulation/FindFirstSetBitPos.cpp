/***
 * 
 * 5 --> 011 --> -1
 * 4 --> 100 --> 3
 * 3 --> 011 --> -1
 * 
 * 1 --> 001 --> 1
 * 2 --> 010 --> 2
 */

#include<bits/stdc++.h>


 int main () {


    int n= 3; int cnt = 0;

    if(!n)
        return n = -1;

    while(n) {

        cnt++;
        if(n & 1) {
            n = n>>1;
            break;
        }
        n = n>>1;
    }

    if(!n) 
        std::cout<<cnt;
    else

    return 0;
 }