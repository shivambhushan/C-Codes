#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool Compare(string a, string b)
{
	if (a.length()==b.length())
	{
		return a<b;
	}
	return a.length()<b.length();
}

// //Sorting string lexicographically and acc to higher length first of element starting with same char
// bool Compare(string a, string b)
// {   
//     if(a.length() < b.length())
//     {
//         if(a == b.substr(0, a.length()))
//             return false;
//     }
//     else if(a.length() >= b.length())
//     {
//         if(b == a.substr(0, b.length()))
//             return true;        
//     }
//     return a<b;
// }

int main()
{
	int n;
	cin>>n;
	vector<string> v;
	for (int i = 0; i < n; ++i)
	{
		string name;
		cin>>name;
		v.push_back(name);
	}

	sort(v.begin(), v.end(), Compare);

	for(string t:v)
	{
		cout<<t<<endl;
	}

	return 0;
}