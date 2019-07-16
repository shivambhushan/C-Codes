#include<bits/stdc++.h>

using namespace std;

int Slowpower(int a, int n)
{
	if (n==0)
	{
		return 1;
	}
	int ans = Slowpower(a, n/2);
	if(n&1)
	{
		return a*ans*ans;
	}
	else
	{
		return ans*ans;
	}
}

// Time -  O(log n)
// Space - O(1)
int Fastpower(int a, int n) //bitmasking
{
	int ans=1;
	while(n>0)
	{
		if (n&1)
		{
			ans *= a;
		}
		a *= a;
		n>>=1;
	}
	return ans;
}

int main()
{
	int a,n;
	cin>>a;
	cin>>n;
	//cout<<Slowpower(a, n);
	cout<<Fastpower(a, n);
	return 0;
}