#include<iostream>

using namespace std;

int main()
{
	int n,p;
	cin>>n>>p;
	int ans = 1;
	while(p>0)
	{
		if((p&1)==1)
		{
			ans *= n;
		}
		n=n*n;
		p = p>>1;
	}
	cout<<ans<<endl;
}