#include<iostream>
using namespace std;
int main()
{
    switch(sizeof(int)) {
        case 4:
            std::cout<<"32 bit configuration";
            break;
        case 8:
            std::cout<<"64 bit configuration";
            break;
        default:
            std::cout<<"Different configuration";
    };
    return 0;
}