#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<long int> h;
    int q, k, type;
    cin>>q>>k;
    long int x, y;
    long int d;

    for(int i = 0; i < k; i++){
        cin>>type;
        cin>>x>>y;
        d = x*x + y*y;
        h.push(d);
    }

    for(int i = 0; i < q-k; i++){
        cin>>type;
        if(type == 1){
            cin>>x>>y;
            d = x*x + y*y;
            if(d < h.top()){
                h.pop();
                h.push(d);
            }
        }
        if(type == 2){
            cout<<h.top()<<endl;
        }
    }

    return 0;
}