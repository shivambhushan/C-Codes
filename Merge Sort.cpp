#include<iostream>

using namespace std;

void Merge(int *arr, int start, int end)
{
	int mid = (start+end)/2;
	int i = start;
	int j = mid+1;
	int k = start;

	int temp[10000];

	while(i<=mid and j<=end)
	{
		if (arr[i]<arr[j])
		{
			temp[k++]=arr[i++];
		}
		else
		{
			temp[k++]=arr[j++];
		}
	}
	while(i<=mid)
	{
		temp[k++]=arr[i++];
	}
	while(j<=end)
	{
		temp[k++] = arr[j++];
	}

	for (int i = start; i <= end; ++i)
	{
		arr[i]=temp[i];	
	}
}

void Merge_Sort(int *arr, int start, int end)
{
	if (start>=end)
	{
		return;
	}
	int mid = (start+end)/2;
	Merge_Sort(arr, start, mid); 
	Merge_Sort(arr, mid+1, end);
	Merge(arr, start, end);
	//return;
} 

int main()
{
	int n;
	cin>>n;
	if (n==0 || n==1)
	{
		return 0;
	}
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	Merge_Sort(arr, 0, n-1);
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}