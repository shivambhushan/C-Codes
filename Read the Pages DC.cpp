#include<bits/stdc++.h>
using namespace std;

bool CanRead(int n, int m, int *p, int pages){
	int pages_read = 0;
	int student = 1;
	for (int i = 0; i < n; ++i){
		if(pages_read + p[i] > pages){
			student++;
			pages_read = p[i];
			if (student > m){
				return false;
			}
		}
		else{
			pages_read += p[i];
		}
	}
	return true;
}

int CalculatePages(int n, int m, int *p){
	int max = p[0];
	for (int i = 0; i < n; ++i){
		if (p[i] > max){
			max = p[i];
		}
		else{
			max = max;
		}
	}
	int s = max;
	int e = accumulate(p, p+4, 0);
	int  ans = e;
	while(s<=e){
		int mid = (s+e)/2;
		if (CanRead(n, m, p, mid)){
			ans =  min(ans, mid);
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
	}
	return ans;
}


int main(){
	int t;
    cin>>t;
    int n, m;
    while(t--){
        cin>>n>>m;
        int p[n];        
        for (int i = 0; i < n; ++i){
            cin>>p[i];
        }
        cout<<CalculatePages(n, m, p);
    }
	return 0;
}