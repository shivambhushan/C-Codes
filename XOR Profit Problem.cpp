#include<iostream>

using namespace std;

int XOR_Profit(int a, int b)
{
	int max_xor = 0;
	for (int i = a; i < b; ++i)
	{
		int check_xor;
		for (int j = a+1; j <= b; ++j)
		{
			check_xor = i^j;
			if (check_xor>max_xor)
			{
				max_xor=check_xor;
			}
		}
	}
	return max_xor;
}

int main()
{
	int a,b;
	cin>>a;
	cin>>b;	
	cout<<XOR_Profit(a, b)<<endl;
	return 0;
}