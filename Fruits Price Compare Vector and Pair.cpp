#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool Compare(pair<string,int> a, pair<string, int> b)
{
	return a.second>b.second;
}

int main()
{
	vector<pair<string, int>> v;
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		string fruit;
		int price;
		cin>>fruit>>price;
		v.push_back(make_pair(fruit, price));
	}
	sort(v.begin(), v.end(), Compare);
	cout<<endl;
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i].first<<" and "<<v[i].second<<endl;
	}
	return 0;
}