#include<iostream>

using namespace std;

bool pathExists(char maze[][10], int i, int j, int m, int n)
{
	//base case
	if (i==m and j==n)
	{
		return true;
	}
	if (i>m or j>n)
	{
		return false;
	}
	if (maze[i][j]=='X')
	{
		return false;
	}

	bool towardsRight = pathExists(maze, i, j+1, m, n);
	if (towardsRight)
	{
		return true;
	}
	return pathExists(maze, i+1, j, m, n);
}

int countPath(char maze[][10], int i, int j, int m, int n)
{
	//base case
	if (i==m and j==n)
	{
		return 1;
	}
	if (i>m or j>n)
	{
		return 0;
	}
	if (maze[i][j]=='X')
	{
		return 0;
	}
	int total_path = countPath(maze, i, j+1, m, n) + countPath(maze, i+1, j, m, n);
	return total_path;
}

void printPath(char maze[][10], int i, int j, int m, int n)
{
	//base case
	if (i==m and j==n)
	{
		maze[i][j] = '1';
		for (int i = 0; i <= m; ++i)
		{
			for (int j = 0; j <= n; ++j)
			{
				cout<<maze[i][j]<<" ";
			}
			cout<<endl;
		}
		maze[i][j]='0';
		cout<<endl;
		return;
	}
	if (i>m or j>n)
	{
		return;
	}
	if (maze[i][j]=='X')
	{
		return;
	}
	maze[i][j]='1';
	printPath(maze, i, j+1, m, n);
	printPath(maze, i+1, j, m, n);
	maze[i][j]='0'; //backtracking
	return;
}

int main()
{
	char maze[10][10] = {
		"00000", 
		"00X0X", 
		"000XX", 
		"XX000", 
		"X0X00" 
	};
	if (pathExists(maze, 0, 0, 4, 4))
	{
		cout<<"Exists"<<endl;
	}
	else
	{
		cout<<"Does not Exists"<<endl;
	}
	cout<<countPath(maze, 0, 0, 4, 4)<<endl;
	cout<<endl;
	printPath(maze, 0, 0, 4, 4);
	return 0;
}