#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool compare1(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}

bool compare2(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

void grandTemple(vector<pair<int, int> > v, int n){
    sort (v.begin() , v.end(), compare1);
    int max1 =0;
    for(int i=0; i<n-1; i++)
    {
        int diff = v[i+1].first - v[i].first - 1;
        if(diff>max1)
        max1 = diff;
    }
    sort (v.begin() , v.end(), compare2);
    int max2 =0;
    for(int i=0; i<n-1; i++)
    {
        int diff = v[i+1].second - v[i].second - 1;
        if(diff>max2)
        max2 = diff;
    }
    cout<<max1*max2;
}

int main() 
{
    int n;
    cin>>n;
    vector<pair<int, int> > v;
    for(int i=0; i<n; i++)
    {
        int int1, int2;
        cin>>int1>>int2;
        v.push_back(make_pair(int1, int2));
    }
    grandTemple(v, n);
    return 0;
}