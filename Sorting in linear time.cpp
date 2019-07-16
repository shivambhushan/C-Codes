#include<bits/stdc++.h>
using namespace std;

void LinearSort(int *arr, int n, int s, int e){
	int m = 0;
	while(m <= e){
		if(arr[m] == 0){
			swap(arr[s], arr[m]);
			s++;
			m++;
		}
		else if(arr[m] == 1){
			m++;
		}
		else{
			swap(arr[m], arr[e]);
			e--;
		}
	}
}

int main(int argc, char const *argv[]){
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i){
		cin>>arr[i];
	}
	LinearSort(arr, n, 0, n-1);
	for (int i = 0; i < n; ++i){
		cout<<arr[i]<<endl;
	}
	return 0;
}