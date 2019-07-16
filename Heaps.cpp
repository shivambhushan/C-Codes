#include <bits/stdc++.h>
using namespace std;

class Heap{
    //private variables and methods
    vector<int> v;
    bool heapTypeMin;
    
    bool compare(int a, int b){
        if(heapTypeMin == false){
            return a<b;
        }
        else{
            return a>b; // minHeap check a=parent and b=child if a>b then swap
        }
    }

    void heapify(int index){
        int left = 2*index;
        int right = 2*index + 1;
        int last_index = v.size() - 1;
        int max_index = index;
        if(left <= last_index and compare(v[index], v[left])){
            max_index = left;
        }
        if(right <= last_index and compare(v[max_index], v[right])){
            max_index = right;
        }
        if(max_index != index){
            swap(v[index], v[max_index]);
            heapify(max_index);
        }
    }

    public:
    Heap(int ds = 10, bool ht = true){
        v.reserve(ds);
        v.push_back(-1); //Block the 0th index
        heapTypeMin = ht;
    }

    //Insertion into heap
    void push(int d){
        v.push_back(d);
        int index = v.size() - 1;
        int parent = index/2;
        while(index > 1 and compare(v[parent], v[index])){
            swap(v[parent], v[index]);
            index = parent;
            parent = parent/2;
        }
    }

    //Get Min or Max element
    int getTop(){
        return v[1];
    }
    
    //Remove Min or Max element
    void pop(){
        //swap first and last node
        int last = v.size() - 1;
        swap(v[1], v[last]);
        //Remove the last node
        v.pop_back();
        //Again check for minHeap or maxHeap
        heapify(1);
    }

    bool empty(){
        return v.size() == 1;
    }
};


int main() {
    int d;
    cin>>d;
    Heap h;
    while(d != -1){
        h.push(d);
        cin>>d;
    }
    while(!h.empty()){
        cout<<h.getTop()<<" ";
        h.pop();
    }
    return 0;
}