#include<iostream>

using namespace std;

int Play_Bits(int n)
{
	while(n>0)
	{
		int a,b;
		cin>>a>>b;
		int ans = 0;
		for (int i = a; i <= b; i++)
		{
			ans += __builtin_popcount(i);
		}
		cout<<ans;
		n--;
	}
	
}

int main()
{
	int n;
	cin>>n;
	Play_Bits(n);
	return 0;
}