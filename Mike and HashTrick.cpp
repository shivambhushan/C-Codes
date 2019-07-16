#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#define ll long long
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}

int main(int argc, char const *argv[])
{
	unordered_map<ll int, ll int> mp;
	ll int n;
	cin>>n;
	vector<ll int> v;
    vector<pair<int, int>> v2;
	ll int x;
	for(ll int i = 0; i < n; i++){
		cin>>x;
		v.push_back(x);
    }
	for(int i = 0; i < n; i++){
		mp[v[i]] = i;
	}
    for(auto itr = mp.begin(); itr != mp.end(); itr++){
		v2.push_back(make_pair(itr->first, itr->second));
	}
	sort(v2.begin(), v2.end(), compare);
	for(int i = 0; i < v2.size(); i++){
        cout<<v2[i].first<<endl;
    }
	return 0;
}