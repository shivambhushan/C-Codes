#include <iostream>
#include<unordered_map>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;


bool anagram(string s1, string s2)
{
	unordered_map<char, int> mp;
	if(s1.size()!= s2.size())
	{
		return false;
	}
	for(int i=0;i<s1.size();i++)
	{
		mp[s1[i]]++;
	}
	for(int i=0;i<s2.size() ; i++)
	{
		if(mp.find(s2[i]) == mp.end())
		{
			return false;
		}
		else
		{
			mp[s2[i]]--;
			if(mp[s2[i]] == 0)
			{
				mp.erase(s2[i]);
			}
		}
	}
	return mp.size() == 0;
}

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<anagram(s1,s2);
	return 0;
}