#include<bits/stdc++.h>

using namespace std;

void inc(int n)//Bottom Up Direction
{
	if (n==0)
	{
		return;
	}
	inc(n-1);
	cout<<n<<" ";
}

void dec(int n)//Top Down Direction
{
	if (n==0)
	{
		return;
	}
	cout<<n<<" ";
	dec(n-1);
}

int main()
{
	int n;
	cin>>n;
	dec(n);
	cout<<endl;
	inc(n);
	return 0;
}