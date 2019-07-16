#include <iostream> 
using namespace std; 
  
int findLength(string& A, int n, int k, char ch) 
{ 
    int maxLength = 1; 
    int cnt = 0; 
    int l = 0, r = 0; 
     
    while (r < n) { 
        if (A[r] != ch) 
            ++cnt; 
        while (cnt > k) { 
            if (A[l] != ch) 
                --cnt; 
            ++l; 
        } 
        maxLength = max(maxLength, r - l + 1); 
        ++r; 
    } 
    return maxLength; 
} 
   
int answer(string& A, int n, int k) 
{ 
    int maxLength = 1; 
    for (int i = 0; i < 26; ++i) { 
        maxLength = max(maxLength, findLength(A, n, k, i+'A')); 
        maxLength = max(maxLength, findLength(A, n, k, i+'a')); 
    } 
    return maxLength; 
} 
  
int main() 
{ 
	int k;
	cin>>k;
	string x;
	cin>>x;
	int n = x.length();
    cout <<answer(x, n, k)<< endl; 
    return 0; 
}