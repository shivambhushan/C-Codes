#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
# define ll long long
using namespace std;

int main(int argc, char const *argv[])
{
    map<ll int, ll int> mp;
    ll int n;
    cin>>n;
    ll int m;
    ll int arr[n];
    for(ll int i = 0; i < n; i++){
        cin>>m;
        arr[i] = m;
        mp[m]++;
    }
    int cmax = 0;
    int max;

    for(auto itr = mp.begin(); itr != mp.end(); itr++){
        if(itr->second > cmax){
            max = itr->first;
            cmax = itr->second;
        } 
    }
    cout<<max;
    return 0;
}