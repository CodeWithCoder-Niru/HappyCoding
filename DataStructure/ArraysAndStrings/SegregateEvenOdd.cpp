/*Segregate even and odd numbers using Lomuto’s Partition Scheme*/
#include<bits/stdc++.h>
using namespace std;

vector<int> arrayEvenAndOdd(vector<int>& arr)
{
    vector<int> Even;
    auto i=-1;
    for(j=0;j<arr.size();j++)
    {
        if(arr[j]%2 == 0)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    return arr;
    
}


int main()
{
    vector<int> arr = { 7, 2, 9, 4, 6, 1, 3, 8, 5 };
    vector<int> updatedArr = arrayEvenAndOdd(arr);

    // Function Call
    cout << "Updated Array: ";
    for (int num : updatedArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}