#include <iostream>
using namespace std;

// LogN Steps
// int count_bits(int n){
//     int ans = 0;
//     while(n>0){
//         ans += (n&1);
//         n = n>>1;
//     }
//     return ans;
// }

//efficent way to computer number of set bits
int count_bits(int n)
{
    int ans = 0;
    while(n>0)
    {
        ans++;
        n = n&(n-1);
    }
    return ans;
}

int main() 
{
    int n,a;
    int count = 0;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        count = count_bits(a);
        cout<<count<<endl;
    }
    cout<<endl<<__builtin_popcount(n)<<endl;
}
