#include<iostream>
#include "Multithreading.hpp"
using namespace std;

// template <typename T>
// T add(T a, T b)
// {
//     return a+b;
// }

//Template Class
template <class T> 
class A {
private:
    T *ptr;
    int size;
public:
    A(T arr[], int s);
    void print();
};

template <class T> 
A<T>::A(T arr[], int s)
{
    ptr = new T[s];
    size = s;
    for(int i=0;i<size;i++)
    {
        ptr[i] = arr[i];
    }
}

template <class T> 
void A<T>::print()
{
    for(auto i=0;i<size;i++)
    {
        cout<<*(ptr+i);
    }
}

int main()
{
    fun();
    int arr[5] = { 1, 2, 3, 4, 5 };
    A<int> a(arr, 5);
    a.print();
    return 0;
}


/*
Program for function template specialization 

template <class T>
void fun(T a)
{
   cout << "The main template fun(): "
        << a << endl;
}
 
template<>
void fun(int a)
{
    cout << "Specialized Template for int type: "
         << a << endl;
}
 
int main()
{
    fun<char>('a');
    fun<int>(10);
    fun<float>(10.14);
}
*/

/*
Program for class template specialization
template <class T>
class Test
{
  // Data members of test
public:
   Test()
   {
       // Initialization of data members
       cout << "General template object \n";
   }
   // Other methods of Test
};
 
template <>
class Test <int>
{
public:
   Test()
   {
       // Initialization of data members
       cout << "Specialized template object\n";
   }
};
 
int main()
{
    Test<int> a;
    Test<char> b;
    Test<float> c;
    return 0;
}
*/