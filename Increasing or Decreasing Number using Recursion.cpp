#include <iostream>
using namespace std;

void Dec_Number(int n)
{
	if (n==0)
	{
		return;
	}
	cout<<n<<" ";
	Dec_Number(n-1);
}

void Inc_Number(int n)
{
	if (n==0)
	{
		return;
	}
	Inc_Number(n-1);
	cout<<n<<" ";
}

int main()
{
	int n;
	cin>>n;
	Inc_Number(n);
	cout<<" and ";
	Dec_Number(n);
	return 0;
}