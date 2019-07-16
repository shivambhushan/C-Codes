#include<iostream>
using namespace std;

class Dog{
public:
	void operator()(){
		cout<<"In Dog operator"<<endl;
		cout<<"Comparing "<<a<<" and "<<b<<endl;
	}

};

int main(int argc, char const *argv[])
{
	Dog funnydog;
	funnydog(); //An Object that behaves like a function - functional obejct or Functor
	return 0;
}