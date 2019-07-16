#include<bits/stdc++.h>

using namespace std;

void Merge(int *arr, int start, int end)
{
	int mid = (start+end)/2;
	int i = start;
	int j = mid+1;
	int k = start;
	int count = 0;
	int temp[100];

	while(i<=mid and j<=end)
	{
		if (arr[i]<arr[j])
		{
			temp[k]=arr[i];
			k++;
			i++;
		}
		else
		{
			temp[k++]=arr[j++];
			count += (mid-i+1);
		}
	}
	while(i<=mid)
	{
		temp[k++]=arr[i++];
	}
	while(j<=end)
	{
		temp[k++]=arr[j++];
	}

	for (int i = start; i < end; ++i)
	{
		arr[i]=temp[i];
	}
	return count;
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
	return;
} 

int main()
{
	int arr[] = {3, 1, 2, 6, 5, 0};
	int n = sizeof(arr)/sizeof(int);
	Merge_Sort(arr, 0, n-1);
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}