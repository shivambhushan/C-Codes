#include<bits/stdc++.h>
using namespace std;

int knapsack(int w[], int p[], int n, int c){
	//BC
	if(n == 0 or c == 0){
		return 0;
	}

	//RC
	int inc, exc;
	inc = exc = INT_MIN;
	if(c-w[n-1] >= 0){
		inc = p[n-1] + knapsack(w, p, n-1, c-w[n-1]);
	}
	exc = knapsack(w, p, n-1, c);
	return max(inc, exc);
}

int knapsackDP(int w[], int p[], int n, int c, int dp[][100]){
	//BC
	if(n == 0 or c == 0){
		return 0;
	}

	if(dp[n][c] != 0){
		return dp[n][c];
	}

	//RC
	int inc, exc;
	inc = exc = INT_MIN;
	if(c-w[n-1] >= 0){
		inc = p[n-1] + knapsackDP(w, p, n-1, c-w[n-1], dp);
	}
	exc = knapsackDP(w, p, n-1, c, dp);
	return dp[n][c] = max(inc, exc);
}

//Bottom-up
int knapsackB(int wt[], int p[], int n, int c){
	int dp[100][100] = {0};
	for(int i = 0; i <= n; i++){
		for(int w = 0; w <= c; w++){
			if(i == 0 or w == 0){
				dp[i][w] = 0;
			}
			else{
				int inc, exc;
				inc = exc = INT_MIN;
				if(w - wt[i - 1] >= 0){
					inc = p[i - 1] + dp[i - 1][w - wt[i - 1]];
				}
				exc = dp[i - 1][w];
				dp[i][w] = max(inc, exc);
			}
			cout<<dp[i][w]<<" ";
		}
		cout<<endl;
		return dp[i][w];
	}
}

int main(int argc, char const *argv[])
{
	int n = 4;
	int dp[100][100];
	int p[] = {50, 30, 40, 80};
	int w[] = {5, 2, 1, 7};
	cout<<knapsack(w, p, n, 7)<<endl;
	cout<<knapsackDP(w, p, n, 7, dp)<<endl;
	cout<<knapsackB(w, p, n, 7)<<endl;
	return 0;
}