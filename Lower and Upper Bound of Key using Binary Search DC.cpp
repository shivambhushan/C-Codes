#include<iostream>
using namespace std;

int LowerBound(int *arr, int n, int key){
	int s = 0;
	int ans = -1;
	int e = n-1;
	while(s<=e){
		int mid = (s+e)/2;
		if (arr[mid]==key){
			ans = mid;
			e = mid - 1;
		}
		else if(arr[mid]>key){
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
	}
	return ans;
}

int UpperBound(int *arr, int n, int key, int l){
	int s = 0;
	int ans = -1;
	int e = n-1;
	while(s<=e){
		int mid = (s+e)/2;
		if (arr[mid]==key){
			ans = mid;
			s = mid + 1;

		}
		else if(arr[mid]>key){
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
	}
	return ans;
}

int main(){
	int n,t;
	cin>>n;
    int arr[n];        
    for (int i = 0; i < n; ++i){
        cin>>arr[i];
    }
    cin>>t;
    while(t--){
		int key;
		cin>>key;
    }
	cout<<"LB and UB are: ";
	cout<<LowerBound(arr, n, key);
	cout<<" & ";
	cout<<UpperBound(arr, n, key, l);
	return 0;
}