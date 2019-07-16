#include <iostream>
using namespace std;

int ways[250];

int Tiling_Problem(int n)
{
	if (ways[n]!=-1)
	{
		return ways[n];
	}
	return (ways[n]=Tiling_Problem(n-1) + Tiling_Problem(n-4));
}

int main()
{
	ways[0]=1;
	ways[1]=1;
	int n;
	cin>>n;
	for (int i = 2; i <= n; ++i)
	{
		ways[i]=-1;
	}
	cout<<Tiling_Problem(n);
	return 0;
}
