#include<iostream>
using namespace std;

//int changed to long long int as per constraints
bool cutTree(long long int n, long long int m, long long int *tree, long long int height){
	long long int tree_height = 0;
	for (long long int i = 0; i < n; ++i){
		long long int cut_on_tree = tree[i];
		if (cut_on_tree - height >= 0){
			tree_height += (cut_on_tree - height);
			if (tree_height >= m){
				return true;
			}
		}
	}
	return false;
}

long long int TreeHeight(long long int n, long long int m, long long int *tree){
	long long int s=0;
	long long int max = 0;
	for (long long int i = 0; i < n; ++i){
		if (max>tree[i]){
			max = max;
		}
		else{
			max=tree[i];
		}
	}
	long long int e=max;
	long long int h = 0;
	while(s<=e){
		long long int mid = (s+e)/2;
		if (cutTree(n, m, tree, mid)){
			h = mid;
			s = mid + 1;
		}
		else{
			e = mid - 1;
		}
	}
	return h;
}

int main(){
	long long int n, m;
	cin>>n>>m;
	long long int tree[n];
	for (long long int i = 0; i < n; ++i)
	{
		cin>>tree[i];
	}
	cout<<TreeHeight(n, m, tree);
	return 0;
}

//1 2 4 -1 -1 -1 3 5 8 -1 -1 -1 6 -1 -1
//1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 8 -1 -1