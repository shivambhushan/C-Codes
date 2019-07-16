#include<iostream>
using namespace std;

bool canCook(int p, int c, int *rank, int mid){
	int count = 0;
	for (int i = 0; i < c; i++){
		int time = 0;
		int x = 1;
		while(time <= mid and rank[i] <=mid){
			time += (rank[i]*x);
			x++;
			if (time <= mid){
				count++;
			}
		}
	}
	if(count >= p){
		return true;	
	}
	else{
		return false;
	}
}


void CookPrata(int p, int c, int *rank){
	int s = 0;
	int e = (p * rank[c-1] * (p+1))/2;
	int time = e;
	while(s < e){
		int mid = (s+e)/2;
		if (canCook(p, c, rank, mid) == 1){
			time = mid;
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
	}
	cout<<endl<<time<<endl;
}

int main(){
	int t;
	cin>>t;
	int p, c;
	while(t--){
		cin>>p>>c;
		int rank[c];
		for (int i = 0; i < c; ++i)
		{
			cin>>rank[i];
		}
		CookPrata(p, c, rank);
	}
	return 0;
}