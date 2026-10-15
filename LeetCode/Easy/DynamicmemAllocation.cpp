#include<iostream>
int main()
{
    int *p = new int[5]; //pointer name treated as array name
    p[0] = 10;
    p[1] = 20;

    std::cout<<p[0];

    delete []p;
    p=nullptr;
    std::cout<<p[1];
}