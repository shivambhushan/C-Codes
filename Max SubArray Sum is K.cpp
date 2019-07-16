//Kadane's Algo - Max subarray sum in O(N)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int arr[]= {2, 3, 5, 7, 1, 6, 3, 4, 8, 2};
	int n = sizeof(arr)/sizeof(int);
	int k;
	cin>>k;
	int start=0, end;
	int Ks=0, Ss=0;
	for (int i = 0; i < n; ++i)
	{
		Ks+=arr[i];
		if (Ks>k)
		{
			Ks-=arr[start];
			start++;
		}
		if (Ks==k)
		{
			break;
		}
	}
	return 0;
}