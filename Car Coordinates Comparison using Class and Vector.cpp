#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Cars
{
public:
	string name;
	int x, y;

	Cars(string n, int x, int y)
	{
		name=n;
		this->x=x;
		this->y=y;
	}
};

bool Compare(Cars a, Cars b)
{
	return a.x*a.x + a.y*a.y < b.x*b.x + b.y*b.y;
}

int main()
{
	int n;
	cin>>n;
	vector<Cars> v;
	for (int i = 0; i < n; ++i)
	{
		string name;
		int x,y;
		cin>>name>>x>>y;
		Cars car(name, x, y);
		v.push_back(car);
	}
	sort(v.begin(), v.end(), Compare);

	for(Cars car:v)
	{
		cout<<car.name<<" "<<car.x*car.x+car.y*car.y<<endl;
	}
	return 0;
}