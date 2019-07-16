#include<bits/stdc++.h>

using namespace std;

void Convert_Alphabet(char *input, char *output, int i, int j)
{
	if (input[i]=='\0')
	{
		output[j]='\0';
		cout<<output<<endl;
		return;
	}

	//include one
	int digit = input[i]-'0';
	char ch = digit+'A'-1;
	output[j]=ch;
	Convert_Alphabet(input, output, i+1, j+1);

	//include two
	if (input[i+1] != '\0')
	{
		int second_digit = input[i+1] - '0';
		int num = 10*digit + second_digit;
		if (num<=26)
		{
			output[j] = num + 'A' -1;
			Convert_Alphabet(input, output, i+2, j+1);
		}
	}
}

int main()
{
	char input[100];
	cin>>input;
	char output[100];
	Convert_Alphabet(input, output, 0, 0);
	return 0;
}