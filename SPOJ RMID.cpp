#include<bits/stdc++.h>
using namespace std;

void comnputeMedian(priority_queue<int> h1 ,priority_queue<int, vector<int>, greater<int> > h2){
    int median;
    if(h1.size() == 1){
        median = h1.top();
    }
    else if(h1.size() == h2.size()){
        median = h1.top();
    }
    else if(h1.size() > h2.size()){
        median = h1.top();

    }
    else if(h1.size() < h2.size()){
        median = h2.top();
    }
    cout<<median<<endl;
}

int main(){
    priority_queue<int, vector<int>, greater<int> > h2;
    priority_queue<int> h1;

    // int t;
    // cin>>t;
    int n;
    //for(int i = 1; i <= t; i++){
        while(scanf("%d", &n) != 0){
            if(n == -1){
                comnputeMedian(h1, h2);
                break;
            }
            else{
                if(h1.empty()){
                    h1.push(n);
                }
                else if(n > h1.top()){
                    h2.push(n);
                    if(h2.size() > h1.size()){
                        int x = h2.top();
                        h2.pop();
                        h1.push(x);
                    }
                }
                else{
                    h1.push(n);
                    if(h1.size() > h2.size()){
                        int x = h1.top();
                        h1.pop();
                        h2.push(x);
                    }
                }
            }
        }
    //}   

    return 0;
}