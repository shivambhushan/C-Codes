#include<iostream>

using namespace std;

int Fibonacci(int n)
{
	if (n==0 || n==1)
	{
		return 1;
	}
	int Fibonacci1=Fibonacci(n-1);
	int Fibonacci2=Fibonacci(n-2);

	return Fibonacci1+Fibonacci2;
}

int main()
{
	int n;
	cin>>n;
	cout<<Fibonacci(n)<<endl;	
	return 0;
}