#include<bits/stdc++.h>
using namespace std;

/*Given an array with all distinct elements, find the largest three elements.*/
int main()
{
    int a[] = {10,4,3,50,23,90};
    int n = sizeof(a)/sizeof(a[0]);
    int first, second, third; 

    // There should be atleast three elements 
    if (n < 3) 
    { 
        cout << " Invalid Input "; 
        return 0; 
    } 

    third = first = second = INT_MIN; 
    for(int i = 0; i < n; i++) 
    { 
        
        // If current element is
        // greater than first
        if (a[i] > first) { 
            third = second; 
            second = first; 
            first = a[i]; 
        } 

        // If arr[i] is in between first
        // and second then update second 
        else if (a[i] > second && a[i] != first)
        { 
            third = second; 
            second = a[i]; 
        } 

        else if (a[i] > third && a[i] != second && a[i] != first) 
            third = a[i]; 
    } 

    cout << "Three largest elements are "
        << first << " " << second << " "
        << third << endl;
}