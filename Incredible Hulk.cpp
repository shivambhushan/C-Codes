#include<iostream>

using namespace std;

int main()
{
	int n,a;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		cout<<__builtin_popcount(a)<<endl;
	}
	return 0;
}