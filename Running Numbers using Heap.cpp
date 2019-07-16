#include <iostream>
#include <queue>
#include <vector>
using namespace std;
    
void printHeap(priority_queue<int, vector<int>, greater<int> > h){
    while(!h.empty()){
            cout<<h.top()<<" ";
            h.pop();
    }
    cout<<endl;
}

int main() {
    priority_queue<int, vector<int>, greater<int> > h; //By default maxHeap - to use minHeap use two more parameters vector and greater<int>
    int no;
    int count = 0;
    int k = 3;
    while(scanf("%d", &no) != EOF){ //EOF ascii value is -1 and its a macro to check end of a file
        if(no == -1){
            //Query
            //Print the heap
            printHeap(h);
        }
        else{
            if(count < k){
                h.push(no);
                count++;
            }
            else{
                if(no > h.top()){
                    h.pop();
                    h.push(no);
                }
            }
        }
    }
    return 0;
}
