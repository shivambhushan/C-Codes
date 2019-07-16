#include <iostream>
using namespace std;

int Min_Index(int *a, int i, int n){
    if(i == n-1){
        return i;
    }
    int min_index = Min_Index(a, i+1, n);

    if(a[i] < a[min_index]){
        return i;
    }
    else return min_index;
}

void Selection(int *a, int i, int n){
    if(n<=1){
        return;
    }
    if(i == n-1){
        return;
    }
    int min_i = Min_Index(a, i, n);
    if(a[i] < a[min_i]){
        Selection(a, i+1, n);
    }
    else{
        swap(a[i], a[min_i]);
        Selection(a, i+1, n);
    }
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    Selection(a, 0, n);
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
}
