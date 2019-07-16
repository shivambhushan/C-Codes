#include<bits/stdc++.h>
using namespace std;

//to start the normal binary search
int BSearchPivot(int *arr, int s, int e, int key){
	if(e < s){
		return -1;
	}
	if (e == s){
		return s;
	}
	int mid = (s+e)/2;
	if (key == arr[mid])
	{
		return mid;
	}
	if (key > arr[mid])
	{
		return BSearchPivot(arr, mid+1, e, key);
	}
	return BSearchPivot(arr, s, mid-1, key);
}

//to get pivot element
int PivotElement(int *arr, int s, int e){
	if(e < s){
		return -1;
	}
	if (e == s){
		return s;
	}
	int mid = (s+e)/2;
	if (mid < e and arr[mid] > arr[mid+1])
	{
		return mid;
	}
	if (mid > s and arr[mid] < arr[mid-1])
	{
		return mid;
	}
	if(arr[s] >= arr[mid]){
		return PivotElement(arr, s, mid-1);
	}
	return PivotElement(arr, mid+1, e);
}

//Comparing key with pivot index element
int FindKey(int n, int key, int *arr){
	int mid = PivotElement(arr, 0, n-1);
	if(mid == -1){
		return BSearchPivot(arr, 0, n-1, key);
	}
	if (arr[mid] == key)
	{
		return mid;
	}
	if (arr[0] <= key)
	{
		return BSearchPivot(arr, 0, mid-1, key);
	}
	return BSearchPivot(arr, mid+1, n-1, key);
}


int main(){
	int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
    	cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<FindKey(n, key, arr);
	return 0;
}