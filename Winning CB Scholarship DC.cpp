 #include<iostream>
using namespace std;

////Brute Force Approach
// long WinScholarship(long n, long m, long x, long y){
// 	long remaining_students = 0;
// 	long left_coupons = 0;
// 	long waiver_students = m/x;
// 	if (n > waiver_students){
// 		remaining_students = n - waiver_students;
// 		left_coupons = m % x;
// 	}
// 	else{
// 		return n;
// 	}

// 	while(remaining_students > 1){
// 		left_coupons += y;
// 		if(left_coupons >= x){
// 			long low_performance_students = left_coupons/x;
// 			if (low_performance_students <= remaining_students){
// 				waiver_students += low_performance_students;
// 				remaining_students -= low_performance_students;
// 				left_coupons = left_coupons % x;
// 			}
// 			else{
// 				waiver_students += remaining_students - 1;
// 				break;
// 			}
// 		}
// 		remaining_students--;
// 	}
// 	return waiver_students;
// }

//Binary Seach Approach
int WinScholarship(int n, int m, int x, int y){
	int s = 0;
	int e = n;
	float ans = 0;
	while(s<=e){
		int mid = (s+e)/2;
		if ((mid*x) <= m + (n-mid)*y){
			ans =  mid;
			s = mid+1;
		}
		else{
			e = mid - 1;
		}
	}
	return ans;
}


int main(){
	int n, m, x, y;
	cin>>n>>m>>x>>y;
	cout<<WinScholarship(n, m, x, y);
	return 0;
}

 