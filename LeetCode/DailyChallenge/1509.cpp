#include<bits/>

class Solution {
public:

    bool isPalindrome(std::string str){
        int l = 0 ;
        int r = str.size()-1;

        while(l < r){
            if(str[l] != str[r])
                return false;

            l++;
            r--;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int left = 0;
        int right = 0;
        int cnt = 0;

        while(right < s.size()){ // abaccdbbd
            if(s[left] == s[right]){
                if(isPalindrome(s.substr(left, right))){
                    left = right + 1;
                    if(s.substr(left, right).size() >= k)
                        cnt++;
                }
            }
            right++;
        }
        return k;
    }
};

int main(){
    Solution S1;
    std::string str{"abaccdbbd"};
    int k = 3;
    std::cout<<S1.maxPalindromes(str, k);
    return 0;
}