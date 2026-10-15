#include<bits/stdc++.h>


std::string reverseWord(std::string &str) {

    std::reverse(str.begin(), str.end());
    int n = str.length();
    std::string ans{""};

    for(int i=0; i < str.length(); i++) {

        std::string word{""};
        while(i < n && str[i] != ' ') {
            word += str[i];
            i++;
        }

        std::reverse(word.begin(), word.end());
        if(word.length() > 0) {
            ans +=" " + word;
        }
    }
    return ans.substr(1);
}


int main() {

    std::string s = "My name is Niranjan";
    std::string final = reverseWord(s);
    std::cout<< final;
    return 0;
}