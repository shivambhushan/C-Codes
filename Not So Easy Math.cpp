#include<bits/stdc++.h>

using namespace std;

int Find_No(int *primes, int n, int N)
{
	int ans = 0;
	for (int i = 1; i < (1<<n); ++i)
	{
		int current_no = i;
		int count_bits = __builtin_popcount(current_no);
		int denom = 1;
		int j = 0;
		while(current_no>0)
		{
			if(current_no&1)
			{
				denom *= primes[j];
			}
			j++;
			current_no>>=1;
		}
		if (count_bits&1)
		{
			ans += N/denom;			
		}
		else
		{
			ans -= N/denom;
		}
	}
	return ans;
}

int main()
{
	int primes[] = {2,3,5};
	int n = sizeof(primes)/sizeof(int);
	int N;
	cin>>N;
	cout<<Find_No(primes, n, N)<<endl;
	return 0;
}