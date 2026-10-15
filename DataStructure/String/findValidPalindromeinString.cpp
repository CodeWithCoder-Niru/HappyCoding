#include<bits/stdc++.h>


bool isPalindrome(std::string const &str) {
   int start=0;
   int end = str.length()-1;

   while(start <= end){
    if(str[start] != str[end])
        return false;

    start++;
    end--;
   }
   return true;
}

int main() {

    int a = 12343;
    bool result = isPalindrome(std::to_string(a));
    std::cout<< result;
    return 0;
}