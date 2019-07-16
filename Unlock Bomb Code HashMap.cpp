#include<iostream>
#include<map>
#include <vector>
using namespace std;

void unlockCode(vector<int> arr, int n, int k){
	map<int, int> mp;
	for(int i = 0; i < n; i++){
		mp.insert(make_pair(arr[i] ,i));
	}
	for(int i = 0; i < n; i++){
		if(k == 0){
			break;
		}
		if(arr[i] == n-i){
			continue;
		}
		mp[arr[i]] = mp[n-i];
		arr[mp[n - i]] = arr[i];
		arr[i] = n-i;
		k--;
	}
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}
}

int main(int argc, char const *argv[])
{
	int n, k;
	cin>>n>>k;
	vector<int> arr;
	int x;
	for(int i = 0; i < n; i++){
		cin>>x;
		arr.push_back(x);
	}
	unlockCode(arr, n, k);
	return 0;
}