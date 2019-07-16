#include<bits/stdc++.h>
using namespace std;

void LCS(string s1, string s2){
	int n = s1.length();
	int m = s2.length();
	int dp[n+1][m+1] = {0};
	vector<char> v;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(i == 0 or j == 0){
				dp[i][j] = 0;
			}
			else if(s1[i-1] == s2[j-1]){
				v.push_back(s2[j-1]);
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout<<dp[n][m]<<endl<<endl;
	for(int i = 0; i < v.size(); i++){
		cout<<v[i];
	}

}

int main(int argc, char const *argv[])
{
	string s1, s2;
	cin>>s1>>s2;
	LCS(s1, s2);
	
	return 0;
}