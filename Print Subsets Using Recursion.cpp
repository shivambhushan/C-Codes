#include<bits/stdc++.h>

using namespace std;

void Generate_Subsets(char *input, char *output, int i, int j)
{
	if (input[i] == '\0')
	{
		output[j]='\0';
		cout<<output<<" ";
		return;
	}

	output[j] = input[i];
	Generate_Subsets(input, output, i+1, j+1);
	Generate_Subsets(input, output, i+1, j);
}

int main()
{
	char input[10], output[10];
	cin>>input;
	Generate_Subsets(input, output, 0, 0);
	return 0;
}