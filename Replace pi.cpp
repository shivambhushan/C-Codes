#include<bits/stdc++.h>

using namespace std;

void Change_pi(char *s, int i)
{
	if (s[i]=='\0' || s[i+1]=='\0')
	{
		return;
	}
	if (s[i]=='p' and s[i+1]=='i')
	{
		int j=i+2;
		while(s[j]!='\0')
		{
			j++;
		}
		while(j>=i+2)
		{
			s[j+2] = s[j];
			j--;
		}
		s[i]='3';
		s[i+1]='.';
		s[i+2]='1';
		s[i+3]='4';
		Change_pi(s, i+4);
	}
	else
	{
		Change_pi(s, i+1);
	}
}

int main()
{
	char s[100];
	cin>>s;
	int i=0;
	Change_pi(s, i);
	cout<<s<<endl;
	return 0;
}