/**
syntax :
[ capture clause ] (parameters) -> return-type  
{   
   definition of method   
}

A lambda expression can have more power than an ordinary function by having access to variables from the enclosing scope. We can capture external variables from the enclosing scope in three ways : 
      Capture by reference 
      Capture by value 
      Capture by both (mixed capture)
Syntax used for capturing variables : 
      [&] : capture all external variables by reference 
      [=] : capture all external variables by value 
      [a, &b] : capture a by value and b by reference
A lambda with an empty capture clause [ ] can only access variables which are local to it. 

what is lambda?
A lambda in C++ is an anonymous (unnamed) function object that you can define directly where you need it.
| Feature                     | Function | Lambda               |
| --------------------------- | -------- | -------------------- |
| Has name                    | Yes      | Usually no           |
| Can capture local variables | ❌ No     | ✅ Yes                |
| Can be defined inline       | ❌ No     | ✅ Yes                |
| Reusable                    | ✅ Yes    | Usually local        |
| Used with STL algorithms    | Possible | Ideal                |
| Compiler creates object     | No       | Yes (closure object) |

**/

#include <bits/stdc++.h>
using namespace std;

/**void print(std::vector<int> v)
{
    for_each(v.begin(), v.end(), [](int i)
    {
        std::cout<<i;
    });
}
int main()
{
    std::vector<int> vec ={1,2,3,4,5,6};
    print(vec);

    std::vector<int>:: iterator p = std::find_if(vec.begin(), vec.end(), [](int i)
    {
        return i > 4;
    });
    std::cout << "First number greater than 4 is : " << *p << std::endl;

    sort(vec.begin(), vec.end(), [](const int& a, const int& b)
    {
        return a > b;
    });
    print(vec);
    return 0;
}*/

//[&] : capture all external variables by reference 
// int main()
// {
//     std::vector<int> v1 = {1,2,3,4};
//     std::vector<int> v2 = {5,6,7,8};

//     auto push = [&](int i)
//     {
//         v1.push_back(i);
//         v2.push_back(i);
//     };
//     push(10);
//     for_each(v1.begin(),v1.end(), [&](int i)
//     {
//         v1.push_back(5);
//         std::cout<<i<<" ";
//     });
//     // access v1 by copy
//     [v1]()
//     {
//         for (auto p = v1.begin(); p != v1.end(); p++)
//         {
//             cout << *p << " ";
//         }
//     };

//     int N = 5;

//     // below snippet find first number greater than N
//     // [N]  denotes,   can access only N by value
//     vector<int>:: iterator p = find_if(v1.begin(), v1.end(), [N](int i)
//     {
//         return i > N;
//     });

//     cout << "First number greater than 5 is : " << *p << endl;

//     // function to count numbers greater than or equal to N
//     // [=] denotes,   can access all variable
//     int count_N = count_if(v1.begin(), v1.end(), [=](int a)
//     {
//         return (a >= N);
//     });

//     cout << "The number of elements greater than or equal to 5 is : "
//          << count_N << endl;
// }

int main(){
    int a =10, b=20;
    []()
    {
        cout<<a<<""<<b;
        a=50;
    }();
    cout<<a;
}
