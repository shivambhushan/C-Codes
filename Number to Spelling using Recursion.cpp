#include <iostream>
using namespace std;

char spellings[][10] = {"zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void Print_Spelling(int n)
{
	if (n==0)
	{
		return;
	}
	Print_Spelling(n/10);
	cout<<spellings[n%10]<<" ";
}


int main()
{
	int n;
	cin>>n;
	Print_Spelling(n);
	return 0;
}
