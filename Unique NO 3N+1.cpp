#include<iostream>

using namespace std;

int Find_Unique_No(int *arr, int n)
{
	int freq[64] = {0};
	for (int i = 0; i < n; i++)
	{
		int temp = arr[i];
		int pos = 0;
		while(temp>0)
		{
			if((temp&1)==1)
			{
				freq[pos]++;
			}
			pos++;
			temp = temp>>1;
		}
	}
	int temp_pos = 1;
	int ans = 0;
	for (int i = 0; i < 64; i++)
	{
		ans += (freq[i]%3)*temp_pos;
		temp_pos = temp_pos<<1;
	}
	cout<<ans<<endl;
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
	Find_Unique_No(arr, n);
	return 0;
}