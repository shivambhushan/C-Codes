#include <bits/stdc++.h>
using namespace std;

void ReplaceAllPi(string str, int i)
{
	if (i>=str.length())
	{
		return;
	}
	if (str[i]=='p' and str[i+1] == 'i')
	{
		cout<<"3.14";
		ReplaceAllPi(str, i+2);
	}
	else
	{
		cout<<str[i];
		ReplaceAllPi(str, i+1);
	}
}

int main()
{
	int n;
	cin>>n;
	string str;
	while(n--)
	{
		cin>>str;
		ReplaceAllPi(str, 0);
		cout<<endl;
	}
	return 0;
}
