#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Fruit{
    public:
    string name;
    int price;
    Fruit(string n, int p){
        name = n;
        price = p;
    }

    Fruit(){

    }

     bool operator()(Fruit a, Fruit b){
        return a.price > b.price;
    }

};

int main() {
    priority_queue<Fruit, vector<Fruit>, Fruit> h;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        string name;
        int price;
        cin>>name>>price;

        Fruit f(name, price);
        h.push(f);

    }
    while(!h.empty()){
        Fruit top = h.top();
        cout<<top.name<<" "<<top.price<<" "<<endl;
        h.pop();
    }
    return 0;
}
