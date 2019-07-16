#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool Compare(int a, int b)
{
	return a>b;
}

int main()
{
	vector<int> v;
	v.reserve(100); //Reserving a space beforehand

	for (int i = 0; i <= 5; ++i)
	{
		v.push_back(i*i); //inserting at end
	}

	v.pop_back();
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<" "; //read or update
	}

	sort(v.begin(), v.end(), Compare);
	cout<<endl;
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<" "; //read or update
	}

	cout<<endl<<v.capacity()<<endl;
	cout<<v.max_size()<<endl;
	
	pair<string, int> p1;
	p1.first = "Apple";
	p1.second = 100;
	cout<<p1.first<<" "<<p1.second;

	vector<pair<string, int>> v1;
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		string fruit;
		int price;
		cin>>fruit>>price;
		v1.push_back(make_pair(fruit, price));
	}
	for (int i = 0; i < v1.size(); ++i)
	{
		cout<<v1[i].first<<" and "<<v1[i].second<<endl;
	}

	return 0;
}