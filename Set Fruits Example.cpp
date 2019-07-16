#include <iostream>
#include <queue>
#include <vector>
#include<set>
using namespace std;

class Fruit{
    public:
    string name;
    int price;
    Fruit(string n, int p){
        name = n;
        price = p;
    }

    Fruit(){} // Important to declare the default constructor

     bool operator()(Fruit a, Fruit b){
        return a.price > b.price;
    }
};

int main() {
    set<Fruit, Fruit> h;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        string name;
        int price;
        cin>>name>>price;

        Fruit f(name, price);
        h.insert(f);
    }
    for(Fruit f:h){
        cout<<f.name<<" "<<f.price<<" "<<endl;
    }
    return 0;
}
