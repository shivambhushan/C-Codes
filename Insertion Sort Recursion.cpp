#include <iostream>
using namespace std;

void Insertion(int *a, int i, int n){
    if(n<=1){
        return;
    }
    if(i == n){
        return;
    }

    int val = a[i];
    int j = i;
    while(j >= 0 and a[j - 1] >= val){
        a[j] = a[j - 1];
        j--;   
    }
    a[j] = val;
    if (i+1 <= n)
    {
        Insertion(a, i+1, n);
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
    Insertion(a, 0, n);
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
}
