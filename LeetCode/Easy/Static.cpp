#include<iostream>

class Static{
    public:
    int a;
    static int b;

    static int fun(int x)
    {
        b=x;
        std::cout<<b;
    }
};
int Static::b;

int main()
{
    Static S1;
    S1.fun(5);
    return 0;
}