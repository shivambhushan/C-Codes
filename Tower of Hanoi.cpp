#include<bits/stdc++.h>

using namespace std;

int TOH(int n)
{
	if (n==1)
	{
		return 1;
	}
	return 2*TOH(n-1)+1;	
}

void TOH_Steps(char src, char dest, char helper, int n)
{
	if (n==0)
	{
		return;
	}
	TOH_Steps(src, helper, dest, n-1);
	cout<<"Moving Disk "<<n<<" from "<<src<<" to "<<dest<<endl;
	TOH_Steps(helper, dest, src, n-1);
}

int main()
{
	int n;
	cin>>n;
	cout<<TOH(n)<<endl;
	TOH_Steps('A', 'C', 'B', n);
	return 0;
}