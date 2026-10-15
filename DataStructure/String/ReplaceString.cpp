/*
std::string& replace(std::size_t pos, std::size_t len, const std::string& str);
std::string& replace(std::size_t pos, std::size_t len, const std::string& str, std::size_t subpos, std::size_t sublen = npos);
std::string& replace(std::size_t pos, std::size_t len, const char* s, std::size_t n);
std::string& replace(std::size_t pos, std::size_t len, const char* s);
std::string& replace(std::size_t pos, std::size_t len, std::size_t n, char c);
*/
/*Replace a substring within the string:*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str = "Good Hello Morning";
    string newstr = "Hi";
    string oldstr = "Hello";

    auto position = str.find(oldstr);
    //cout<<position<<endl;
    while(position != string::npos)
    {
        str.replace(position, oldstr.length(), newstr);
        cout<<position<<endl;
        position = str.find(oldstr);
        cout<<position<<endl;
    } 
    cout<<str;
}