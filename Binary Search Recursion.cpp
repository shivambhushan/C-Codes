#include<iostream>
using namespace std;

int BinarySearch(int *arr, int n, int start, int end, int key)
{
	int mid = (start+end)/2;
	if (start==n)
	{
		return -1;
	}
	if (key==arr[mid])
	{
		cout<<"Found at index: ";
		return mid;
	}
	if (key<arr[mid])
	{
		return BinarySearch(arr, n, start, mid-1, key);
	}
	if (key>=arr[mid+1])
	{
		return BinarySearch(arr, n, mid+1, end, key);
	}
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
	cout<<BinarySearch(arr, n, 0, n-1, key);
	return 0;
}