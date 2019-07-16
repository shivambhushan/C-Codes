#include<bits/stdc++.h>
using namespace std;

void Generate_Paranthesis(int n, char output[], int i, int open, int close)
{
	//Base Case
	if (i==2*n)
	{
		output[i]='\0';
		cout<<output<<endl;
		return;
	}

	//Rec Case
	if (open<n)
	{
		output[i]='(';
		Generate_Paranthesis(n, output, i+1, open+1, close);
	}
	if (close<open)
	{
		output[i]=')';
		Generate_Paranthesis(n, output, i+1, open, close+1);
	}
}

int main()
{
	int n; 
	cin>>n;
	char output[10];
	Generate_Paranthesis(n, output, 0, 0, 0);
	return 0;
}