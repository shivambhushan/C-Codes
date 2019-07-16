#include<bits/stdc++.h>
using namespace std;

class Compare{
    public:
    Compare(){}

    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second>b.second;
    }
};

int main(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> h;
    int k,n;
    cin>>k>>n;
    int data;
    pair<int, int> arr[k][n];

    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            cin>>data;
            arr[i][j] = make_pair(i, data);
        }
    }

    for(int i = 0; i < k; i++){
        h.push(arr[i][0]);
    }

    int temp[k];
    fill_n(temp, k, 1);
    int id = 0;
    int index;
    int ans[k*n];
    while(!h.empty()){
        ans[id] = h.top().second;
        id++;
        index = h.top().first;
        h.pop();
        
        for(int i = 0; i < k; i++){
            if(index == i and temp[index] < n){
                h.push(arr[index][temp[index]]);
                temp[index]++;
                break;
            }
        }
    }
    
    for(int i = 0; i < k*n; i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}