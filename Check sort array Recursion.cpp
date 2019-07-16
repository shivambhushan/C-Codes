#include <iostream>
using namespace std;

bool isSorted(int *arr, int n)
{
	if (n==1)
	{	
		return true;
	}
	if(arr[0]<=arr[1] and isSorted(arr+1, n-1))
	{
		return true;
	}
	return false;
}

	// //Base Case
	// if (n==0 || n==1)
	// {
	// 	return true;
	// }
	// if (arr[n] < arr[n-1])
	// {
	// 	return false;
	// }

	// //Recursive Case
	// return isSorted(arr, n-1);

int main() {
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
    	cin>>arr[i];
    }
    if (isSorted(arr, n))
    {
    	cout<<"true"<<endl;
    }
    else
    {
    	cout<<"false"<<endl;
    }
    return 0;
}
