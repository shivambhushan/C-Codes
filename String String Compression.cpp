#include<iostream>
using namespace std;

void stringCompression(string x){
    string y = "";
    char n = x[0];
    char prev = x[0];
    int cur_len = 1;
    for(int i=1;i<x.length();i++) {
        n = x[i];
        if(n==prev) {
            cur_len++;
            prev = n;
        }
        else {
            if(cur_len>1)
                y  = y + string(1,prev) + to_string(cur_len);
            else
                y  = y + string(1,prev);
            prev = n;
            cur_len = 1;
        }
    }
    if(cur_len>1)
        y  = y + string(1,prev) + to_string(cur_len);
    else
        y  = y + string(1,prev);
    cout<<y<<endl;
}

int main() {
    string x;
    cin>>x;
    stringCompression(x);
	return 0;
}