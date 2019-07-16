#include<bits/stdc++.h>
using namespace std;

bool canPlace(int n, int *stalls, int C, int separation){
	int cows_placed = 1;
	int last_placed_cow = stalls[0];

	//remaining stalls	
	for (int i = 0; i < n; ++i){
		int cow_stall = stalls[i];
		if (cow_stall - last_placed_cow >= separation){
			cows_placed++;
			last_placed_cow = cow_stall;
			if (cows_placed == C)
			{
				return true;
			}
		}
	}
	return false;
}

int main(){
	int n,cows;
	cin>>n>>cows;
	int stalls[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>stalls[i];
	}
    sort(stalls, stalls+n);
	int s = 0;
	int e = stalls[n-1]- stalls[0];
	int ans = 0;
	while(s<=e){
		int mid = (s+e)/2;
		if (canPlace(n, stalls, cows, mid)){
			ans = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}

	cout<<ans<<endl;
	return 0;
}