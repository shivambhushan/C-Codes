#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;

int main(int argc, char const *argv[])
{
	unordered_map<string, int> m;
	m.insert(make_pair("mango", 100));
	m["apple"] = 200;
	m["apple"] += 20;

	//Search
	if(m.count("Guava") == 0){
		cout<<"Not Present"<<endl;
	}
	else{
		cout<<m["Guava"]<<endl;
	}

	//search using find function
	auto f = m.find("mango"); //auto is a datatype
	// or use unordered_map<string, int>::iterator f = m.find("mango");
	if(f != m.end()){
		cout<<f->first<<" and "<<f->second<<endl;
	}

	//print/extract an element
	cout<<m["apple"]<<endl;
	m.erase("apple");
	
	m["pineapple"] = 90;
	for(auto p: m){
		cout<<p.first<<" and "<<p.second<<endl;
	}

	return 0;
}