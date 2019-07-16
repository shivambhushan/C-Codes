#include <bits/stdc++.h>
using namespace std;

void Check_Index(int *arr, int n, int m, int *out, int &out_pos)
{
    if(n==-1)
    {
        return;
    }
    if(arr[n]==m)
    {
        out[out_pos++]=n;
    }
    Check_Index(arr, n-1, m, out, out_pos);
}

int main() 
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; ++i) 
    {
        cin>>arr[i];
    }
    int out[100];
    int out_pos=0;
    int m;
    cin>>m;
    Check_Index(arr, n-1, m, out, out_pos);
    for (int i = out_pos-1; i >= 0; --i)
    {
        cout<<out[i]<<" ";
    }
    return 0;
}