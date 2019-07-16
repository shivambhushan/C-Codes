#include<iostream>
#include<unordered_map>
#define ll long long
using namespace std;

int main(int argc, char const *argv[])
{
	ll int t;
	cin>>t;
    unordered_map<ll int, bool> mp;
	while(t--){
		ll int n, q;
		cin>>n;
		ll int arr[n];
		for(ll int i = 0; i < n; i++){
			cin>>arr[i];
            mp[arr[i]] = true;
		}
		cin>>q;
        ll int num;
		for(ll int i = 0; i < q; i++){
			cin>>num;
			if(mp[num]){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
		}
        mp.clear();
	}
	return 0;
}