// CPP program to demonstrate using a function on left side
// of an expression in C++
#include <iostream>
using namespace std;
 
// such a function will not be safe if x is non static
// variable of it
int& fun()
{
    static int x;
    return x;
}
 
// Driver Code
int main()
{
    fun() = 10;
    printf(" %d ", fun());
    return 0;
}