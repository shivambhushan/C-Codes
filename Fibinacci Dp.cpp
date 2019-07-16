#include<iostream>
using namespace std;

int memo[1000];

//top-down - Memoization
int fibT(int n){
	if(n == 0) return 0;
	if(n == 1) return 1;

	if(memo[n] != -1){
		return memo[n];
	}
	int ans = fibT(n - 1) + fibT(n - 2);
	memo[n] = ans;
	return ans;
}

//bottom-up - Pure dp
int fibB(int n){
	int dp[1000];

	dp[0] = 0;
	dp[1] = 1;

	for(int i = 2; i <= n; i++){
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

int main(){
	int n;
	cin>>n;
	for(int i = 0; i <= n; i++){
		memo[i] = -1;
	}

	int ans = fibT(n);
	int ans1 = fibB(n);
	cout<<ans<<endl;
	cout<<ans1<<endl;

	return 0;
}