//Kadane's Algo - Max subarray sum in O(N)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int arr[]= {2, -3, 4, -1, 6, 5, -3, 2};
	int n = sizeof(arr)/sizeof(int);
	int cs=0, ms=0;
	for (int i = 0; i < n; ++i)
	{
		cs += arr[i];
		if (cs<0)
		{
			cs=0;
		}
		ms=max(ms,cs);
	}
	cout<<ms<<endl;
	return 0;
}