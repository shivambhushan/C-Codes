#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
    unordered_map<int, int> mp;
    int n;
    cin>>n;
    int m;
    vector<int> v;
    int result = 0;
    for(int i = 0; i < n; i++){
        cin>>m;
        v.push_back(m);
    }
    for(int i = 0; i < n; i++){
        int j = i;
        while(mp.find(v[j]) == mp.end() and j < n){
            mp[v[j]]++;
            j++;
        }
        result += ((mp.size()*(mp.size()+1))/2);
        mp.clear();
    }
    cout<<result;
    return 0;
}

// #include<iostream>
// #include<unordered_map>
// #include<vector>
// #include<algorithm>
// # define ll long long
// using namespace std;

// int main(int argc, char const *argv[])
// {
//     unordered_map<int, int> mp;
//     int n;
//     cin>>n;
//     int m;
//     vector<int> v;
//     int result = 0;
//     for(int i = 0; i < n; i++){
//         cin>>m;
//         v.push_back(m);
//     }
//     for(int i = 0; i < n; i++){
//         int j = i;
//         while(mp.find(v[j]) == mp.end() and j < n){
//             mp[v[j]] = mp.size()+1;
//             j++;
//         }
//         for(auto itr = mp.begin(); itr != mp.end(); itr++){
//             result += itr->second;
//         }
//         mp.clear();
//     }
//     cout<<result;
//     return 0;
// }