#include<bits/stdc++.h>
using namespace std;

//Recursive Approach
int winesR(int a[], int i, int j, int y){
	//BC
	if(i > j){
		return 0;
	}
	int op1 = a[i] * y + winesR(a, i + 1, j, y+1);
	int op2 = a[j] * y + winesR(a, i, j -1 , y+1);

	return max(op1, op2);
}

//Bottom-up
int winesB(int a[], int i, int j, int y){
	
}

int main(int argc, char const *argv[])
{
	int w[] = {2, 3, 5, 1, 4};
	int n = sizeof(w)/sizeof(int);
	cout<<winesR(w, 0, n-1, 1)<<endl;
	
	return 0;
}