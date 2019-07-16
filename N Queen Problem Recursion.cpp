#include<iostream>

using namespace std;

bool isSafe(int board[10][10], int x, int y, int n)
{
	//column
	for (int i = 0; i < x; ++i)
	{
		if (board[i][y] == 1)
		{
			return false;
		}
	}

	int a, b;
	//left diagonal
	a = x, b = y;
	while(a>=0 and b>=0)
	{
		if (board[a][b]==1)
		{
			return false;
		}
		a--;
		b--;
	}

	//right diagonal
	a = x, b = y;
	while(a>=0 and b<n)
	{
		if (board[a][b]==1)
		{
			return false;
		}
		a--;
		b++;
	}
	return true;
}

void SolveNQueen(int n, int board[10][10], int i, int &count)
{
	//base case
	if (i==n)
	{
		//print the board
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		count++;
		cout<<endl;
		return;
	}

	//rec case
	for (int j = 0; j < n; ++j)
	{
		if (isSafe(board, i, j, n))
		{
			board[i][j] = 1;
			SolveNQueen(n, board, i+1, count);
		}
		board[i][j]=0;
	}
}

int main()
{
	int count = 0;
	int n;
	cin>>n;
	int board[10][10] = {0};
	SolveNQueen(n, board, 0, count);
	cout<<count;
	return 0;
}