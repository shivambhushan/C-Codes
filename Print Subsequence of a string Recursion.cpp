#include <bits/stdc++.h>
using namespace std;

void SubSeq(string str, int index)
{
	if (index == pow(2, str.length()))
	{
		return;
	}

	string str1 = " ";
	for (int i = 0; i < str.length(); ++i)
	{
		int temp = index>>i;
		int last_bit = temp&1;
		if (last_bit)
		{
			str1= str[str.length()-i-1] + str1;
		}
	}
	cout<<str1<<" ";
	SubSeq(str, index+1);
}

int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	SubSeq(str, 0);
	int n = pow(2, str.length());
	cout<<endl<<n;
	return 0;
}