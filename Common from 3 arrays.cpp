#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	map<int, int> mp;
	int n;
	cin>>n;
	int arr1[n];
	int arr2[n];
	int arr3[n];
	for(int i = 0; i < n; i++){
		cin>>arr1[i];
	}
	for(int i = 0; i < n; i++){
		cin>>arr2[i];
	}
	for(int i = 0; i < n; i++){
		cin>>arr3[i];
	}
	for(int i = 0; i < n; i++){
		mp[arr1[i]]++;
		mp[arr2[i]]++;
		mp[arr3[i]]++;
	}
	for(auto itr = mp.begin(); itr != mp.end(); itr++){
		if(itr->second == 3){
			cout<<itr->first<<" ";
		}
	}
	// print hashmap
	// for(auto itr = mp.begin(); itr != mp.end(); itr++){
	// 	cout<<itr->first<<" "<<itr->second<<endl;
	// }
	return 0;
}