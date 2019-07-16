#include<iostream>

using namespace std;

int Find_Unique_No(int *arr, int n)
{
	int pos = -1;
	int unique_no1 = 0;
	int unique_no2 = 0;
	int unique_no3 = 0;
	for (int i = 0; i < n; ++i)
	{
		unique_no1 = unique_no1^arr[i];
	}
	while(unique_no1>0)
	{
		int check = unique_no1&1;
		pos = pos+1;
		if (check==1)
		{
			break;
		}
		else
		{
			unique_no1 = unique_no1>>1;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (((arr[i]>>pos)&1)==1)
		{
			unique_no2 = unique_no2^arr[i];
		}
	}

	unique_no3=unique_no1^unique_no2;
	cout<<unique_no3<<endl<<unique_no2<<endl;
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