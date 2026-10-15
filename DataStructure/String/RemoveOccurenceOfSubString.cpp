#include<bits/stdc++.h>


std::string removeOccurence(std::string &str, std::string const &part){

    while(str.length() > 0 && str.find(part) < str.length()) {

        str.erase(str.find(part), part.length());
    }
    return str;
}


int main() {

    std::string str{"daabcbaabcbc"};
    std::string part{"abc"};

    std::string result = removeOccurence(str, part);

    std::cout<<result;
    return 0;
}