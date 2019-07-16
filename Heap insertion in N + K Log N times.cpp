#include <bits/stdc++.h>
using namespace std;

void heapify(int *arr, int i, int n){
    int left = i<<1;
    int right = left + 1;
    int max_index = i;
    if(left < n and arr[i] < arr[left]){
        max_index = left;
    }
    if(right < n and arr[max_index] < arr[right]){
        max_index = right;
    }
    if(max_index != i){
        swap(arr[i], arr[max_index]);
        heapify(arr, max_index, n);
    }
}

int main() {
    int arr[] = {-1, 2, 4, 1, 5, 3, 0};
    int n = sizeof(arr)/sizeof(int);

    //convert array into heap --> O(N)
    for(int i = n/2; i >= 1; i--){
        heapify(arr, i, n);
    }

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}