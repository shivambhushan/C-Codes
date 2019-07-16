#include<bits/stdc++.h>

using namespace std;

void Bubble_Sort(int *arr, int i, int n)
{
	if (n<=1)
	{
		return;
	}

	if (i==n-1)
	{
		Bubble_Sort(arr, 0, n-1);
		return;
	}

	if (arr[i]>arr[i+1])
	{
		swap(arr[i], arr[i+1]);
	}
	Bubble_Sort(arr, i+1, n);
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
	Bubble_Sort(arr, 0, n);
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}