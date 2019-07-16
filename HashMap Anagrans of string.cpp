#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;

bool anagram(string s1, string s2){
	if(s1.size() != s2.size()){
		return false;
	}
	unordered_map<char, int> mp;
	for (int i = 0; i < s1.size(); ++i){
		mp[s1[i]]++; //insertion
	}
	for (int i = 0; i < s2.size(); ++i){
		if(mp.find(s2[i]) == mp.end()){
			return false;
		}
		else{
			mp[s2[i]]--;
			if(mp[s2[i]] == 0){
				mp.erase(s2[i]);
			}
		}
	}
	return mp.size() == 0;

}

int main(int argc, char const *argv[])
{
	string s1, s2;
	cin>>s1>>s2;
	cout<<anagram(s1, s2)<<endl;
	return 0;
}