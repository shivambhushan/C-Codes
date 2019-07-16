#include<bits/stdc++.h>

using namespace std;

void filterChars(char *s, int i)
{
	int temp = i;
	int j = 0;
	while(temp>0)
	{
		int last_bit = temp&1;
		if(last_bit)
		{
			cout<<s[j]<<endl;
		}
		j++;
		temp = temp>>1;
	}
}

void printSubsets(char *s)
{
	int n = strlen(s);
	for (int i = 0; i < (1<<n); ++i)
	{
		filterChars(s, i);
	}
}

int main()
{
	char s[100];
	cin>>s;
	printSubsets(s);
	return 0;
}