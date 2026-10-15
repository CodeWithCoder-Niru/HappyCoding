/* Syntax : pair <data_type1, data_type2> pairname
Pair_name = make_pair (value1,value2);*/

#include<iostream>
#include<utility>
using namespace std;

int main()
{
    pair<int, char> Pair1;
    Pair1.first=10;
    Pair1.second='N';
    cout<<Pair1.first<<" ";
    cout<<Pair1.second;
}