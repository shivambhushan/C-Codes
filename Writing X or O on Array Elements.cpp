#include<bits/stdc++.h>

using namespace std;

void Permute(char *str, int i)
{
	if (str[i]=='\0')
	{
		cout<<str<<endl;
	}
	for (int j = i; str[j]!='\0'; ++j)
	{
		str[i]='X';
		Permute(str, i+1);
		str[i]='O';
	}
}

int main()
{
	char str[10];
	cin>>str;
	int n = strlen(str);
	Permute(str, 0);
	return 0;
}