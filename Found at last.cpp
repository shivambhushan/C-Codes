#include <iostream>
using namespace std;

int Check_Index(int *arr, int n, int m, int l)
{
    if(n==0)
    {
        return -1;
    }
	else
	{
		int index = Check_Index(arr+1, n-1, m, l);
        if(m==arr[0])
        {
            if (index>l-n)
            {
                return index;
            }
            else
            {
                return l-n;
            }
        }
		else
        return index;
	}
}

int main() 
{
    int n, l;
    cin>>n;
    l=n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
    	cin>>arr[i];
    }
    int m;
    cin>>m;
    cout<<Check_Index(arr, n, m, l)<<endl;
    return 0;
}