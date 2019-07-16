#include <bits/stdc++.h>
using namespace std;

string Move_X(string s, int n){
	if (n<=1){
		return s;
	}
	if (s.at(0) == 'x'){
		s = Move_X(s.substr(1, n-1), n-1) + "x";
		return s;
	}
	else{
		s = s[0] + Move_X(s.substr(1, n-1), n-1);
		return s;
	}
}

int main(){
	string s;
	cin>>s;
	int n = s.length();
	cout<<Move_X(s, n);
	return 0;
}