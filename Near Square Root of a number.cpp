#include<iostream>
using namespace std;

float NearSquareRoot(int n, int p){
	int s = 0;
	int e = n;
	float ans = 0;
	while(s<=e){
		int m = (s+e)/2;
		if (m*m == n){
			return m;
		}
		else if (m*m <= n){
			ans =  m;
			s = m + 1;
		}
		else{
			e = m - 1;
		}
	}
	float inc = 0.1;
	for (int times = 1; times <= p; ++times){
		while(ans*ans<=n){
			ans += inc;
		}
		ans = ans - inc;
		inc = inc/10;
	}
	return ans;
}

int main(){
	int n, p;
	cin>>n>>p;
	cout<<NearSquareRoot(n, p);
	return 0;
}	