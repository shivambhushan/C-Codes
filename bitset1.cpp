#include <bits/stdc++.h>
using namespace std;

int main() {
	// int n;
	// cin>>n;
	// b = n;
	// cout<<b<<endl;
	// int l,h;
	// cin>>l>>h;
	// for(int i=l;i<=h;i++) {
	// 	b.set(i);
	// }
	// cout<<b<<endl;
	// b.reset(2);
	// cout<<b<<endl;
	// int x = b.to_ulong();
	// cout<<x<<endl;
	// string x;
	// string y;
	// cin>>x>>y;
	// bitset<32> a(x);
	// bitset<32> b(y);
	// cout<<a<<endl<<b<<endl;
	// int x1 = a.to_ulong()+b.to_ulong();
	// bitset<32> c(x1);
	bitset<64> d;
	d=0;
	for(int i=0;i<64;i++)
	{
		d.set(i);
	}
	cout<<d<<endl;
	cout<<d.size()<<endl;
	cout<<d.to_ullong()<<endl; //for long int.
	cout<<d.size()<<endl;

	// cout<<c;
	return 0;
}