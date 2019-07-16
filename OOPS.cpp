#include <bits/stdc++.h>
using namespace std;

class Car{
	private:
		int price;

	public:
		//Data Members - By default data members are private
		char* color;
		char* name;

	//default constructor
	Car(){ //called all by itself when an object is created
		price = 1000;
		name =  "abc";
		color = "black";
	}

	//parameterized constructor
	Car(char *n, char* c, int p){ 
		price = p;
		name = n;
		strcpy(color, c);
	}

	// //copy constructor - shallow copy const
	// Car(Car &X){ //pass by reference
	// 	cout<<"Shallow Copy Const"<<endl;
	// 	price = X.price; // addresses are passed
	// 	name = X.name;
	// 	color = X.color;
	// }

	// Deep Copy Const
	Car(Car &Y){
		cout<<"Deep Copy Const"<<endl;
		int len_name = strlen(Y.name);
		int len_color = strlen(Y.color);
		name = new char[len_name];
		color = new char[len_color];
		strcpy(name, Y.name);
		strcpy(color, Y.color);
		price = Y.price;
	}

	//Setter and getter functions to limit input
	void set_price(int p){
		price = p;
	}

	void get_price(){
		cout<<price<<endl;
	}

	void print(){
		cout<<name<<endl;
		cout<<color<<endl;
		cout<<price<<endl;
	}

	//0perator Overloading
	void operator+(){
		cout<<name<<" is a Car"<<endl;
	}

	void operator!(){
		cout<<price<<" is not the exact price of Car"<<endl;
	}
};

//declared outside the car class as ostream is already a class
ostream& operator<<(ostream &a, Car c){
		c.print();
		return a;
	}

istream& operator>>(istream &b, Car &c){
	char* color;
	cin>>color;
	strcpy(c.color, color);
	char* name;
	c.name = name;
	strcpy(c.name, name);
	// int p;
	// cin>>p;
	// c.set_price(p);
	return b;
}

int main(int argc, char const *argv[])
{
	//Car c1 = new Car(); //new helps for Dynamuc Memory Allocation
	Car c1;
	char a[10] = "Blue";
	c1.color = a;
	char b[10] = "Ciaz";
	c1.name = b;
	// cout<<c1.color<<" "<<c1.name<<" ";
	c1.set_price(1000);
	//c1.get_price();
	Car c2;
	// cout<<c2.color<<" "<<c2.name<<" ";
	// c2.get_price();
	Car* c3 = new Car("BMW", "White", 500); // * for dynamic memory allocation
	// c3->print(); // -> for pointer to class
	// return 0;
	//c1.print();
	Car c4(c1); // calls a copy constructor
	c4.print();
	cout<<endl;
	//c1.color = "yellow";
	c4.color[2] = 'X'; //Shallow Copy - changes(based on addresses) in c4 will be reflected in c1 also
	c4.name[2] = 'X';
	c4.print();
	cout<<endl;
	c1.print();
	// +c1; //calling the overloaded the operator
	// !c1;
	// Car c5;
	// cin>>c1;
	// cout<<c1<<endl;
	return 0;
}