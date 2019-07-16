#include<iostream>
using namespace std;

int LinearSearch(int *arr, int n, int i, int key)
{
	if (i==n)
	{
		return -1;
	}
	if (arr[i]==key)
	{
		return i;
	}
	return LinearSearch(arr, n, i+1, key);
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
	int key;
	cout<<"Enter Key: ";
	cin>>key;
	cout<<LinearSearch(arr, n, 0, key);
	return 0;
}