/*Rearrange array such that even positioned are greater than odd*/
#include<bits/stdc++.h>
using namespace std;
void assign(int a[], int n)
{
    int neg = 0, pos= n-1;
    int ans[n];
    sort(a, a+n);
    for(auto i=0;i<n;i++)
    {
        if(i%2 == 0)
        {
            ans[i] = a[pos--];
        }
        else
        {
            ans[i] = a[neg++];
        }
    }

    for(auto i=0;i<n;i++)
    {
        cout<<ans[i];
    }
    
}

int main()
{
    int arr[] = { 2,1,5,6,7,3,1 };
    int N = sizeof(arr) / sizeof(arr[0]);
    assign(arr, N);
    return 0;
}