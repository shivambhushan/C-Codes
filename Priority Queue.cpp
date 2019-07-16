#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Compare{
    public:
    bool operator()(int a, int b){
        return a<b;
    }
};

int main() {
    // priority_queue<int> h;
    // priority_queue<int, vector<int>, greater<int> > h; //By default maxHeap - to use minHeap use two more parameters vector and greater<int>
    priority_queue<int, vector<int>, Compare> h;
    int arr[] = {1, 2, 3, 5, 0, 8, 7};
    int n = sizeof(arr)/sizeof(int);

    for(int i = 0; i < n; i++){
        h.push(arr[i]);
    }
    while(!h.empty()){
        cout<<h.top()<<" ";
        h.pop();
    }
}
