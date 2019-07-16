#include<iostream>

using namespace std;

int Left[40] = {0}, Right[40] = {0}, Column[40] = {0};

int countQueen(int n , int i)
{
	//B C
	if (i==n)
	{
		return 1;
	}

	//R C
	int count = 0;
	for (int j = 0; j < n; ++j)
	{
		if (Column[j] == 0 and Left[i-j+(n-1)]==0 and Right[i+j]==0)
			{
				Column[j] = Left[i-j+(n-1)] = Right[i+j] = 1;
				count += countQueen(n, i+1);
				Column[j] = Left[i-j+(n-1)] = Right[i+j] = 0;
			}	
	}
	return count;
}

int main()
{
	int n;
	cin>>n;
	cout<<countQueen(n, 0);
	return 0;
}