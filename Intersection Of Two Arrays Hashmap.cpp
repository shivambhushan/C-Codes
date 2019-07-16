#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	map<int, int> mp;
	int n;
	cin>>n;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	int x, y;
	for(int i = 0; i < n; i++){
		cin>>x;
		v1.push_back(x);
        mp[x]++;
	}
    for(int i = 0; i < n; i++){
        cin>>y;
		v2.push_back(y);
    }
	sort(v2.begin(), v2.end());
    int num;
	for(int i = 0; i < n; i++){
        num = v2[i];
        if(mp[num] > 0){
            v3.push_back(num);
            mp[num]--; 
        }
	}
    cout<<"[";
	for(int i = 0; i < v3.size() - 1; i++){
		cout<<v3[i]<<", ";
	}
    cout<<v3[v3.size()-1]<<"]"<<endl;
	return 0;
}