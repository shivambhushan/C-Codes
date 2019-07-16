#include<iostream>
#include<algorithm>
using namespace std;


void Wave(int *a, int n, int i){
	if (n<=1){
		return;
	}
	if (i == n-1){
		return;
	}
	//sort(a, a+n);
	while(i<=n){
		if (i > 0 and a[i-1] > a[i]){
			swap(a[i], a[i-1]);
			Wave(a, n, i+2);
	 	}
		else{
			if(i+2 <= n){
				Wave(a, n, i+2);
			}
		}
	}
}

int main(){
	int n = 6;
	int a[] = {1, 3, 4, 2, 7, 8};
	Wave(a, n, 0);
	for (int i = 0; i < n; ++i){
		cout<<a[i]<<" ";
	}
	return 0;
}