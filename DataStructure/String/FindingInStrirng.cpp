#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str = "Hello world";
    string substr = "o";

    auto position = str.find(substr);
    if(position != string::npos)
    {
        cout<<position;
        str.erase(str[position]);
    }
}



/*
std::string::find: Finds the first occurrence of a substring or character.
std::string::rfind: Finds the last occurrence of a substring or character.
Looping with find: To find all occurrences of a substring or character.
Case insensitive search: Convert strings to the same case before searching.
*/