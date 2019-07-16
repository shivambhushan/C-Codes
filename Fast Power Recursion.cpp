#include<iostream>
using namespace std;

// //less optimized - takes b steps - O(N)
// int Compute_Power(int a, int b)
// {
// 	if (b==0)
// 	{
// 		return 1;
// 	}
// 	else
// 	{
// 		return a*Compute_Power(a, b-1);
// 	}
// }

//more optimized - takes b/2 steps - O(log N)
int Fast_Power(int a, int b)
{
	if (b==0)
	{
		return 1;
	}
	int ans = Fast_Power(a, b/2);
	ans *= ans;
	if (b&1)
	{
		return a*ans;
	}
	return ans;
}

int main()
{
	int a,b;
	cin>>a>>b;
	//cout<<Compute_Power(a,b)<<endl;
	cout<<Fast_Power(a,b)<<endl;
	return 0;
}