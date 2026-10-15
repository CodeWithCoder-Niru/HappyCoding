#include<iostream>
using namespace std;

int main()
{
    float widthofPaper = 0.0001;
    uint64_t distance = 1;
    uint64_t Folds;
    std::cin>>Folds;
    for(auto i = 1 ; i<=Folds ; i++){
        distance = 2*distance;
    }
    std::cout<<"Distance covered to reach moon :"<<distance*widthofPaper;
    return 0;
}