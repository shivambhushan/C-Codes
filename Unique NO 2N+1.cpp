 #include<iostream>

using namespace std;

int Find_Unique_No(int *arr, int n)
{
	int unique_no = 0;
	for (int i = 0; i < n; ++i)
	{
		unique_no = unique_no^arr[i];
	}
	return unique_no;
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
	cout<<Find_Unique_No(arr, n)<<endl;
	return 0;
}