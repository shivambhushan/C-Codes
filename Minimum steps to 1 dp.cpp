#include <iostream>
#include <climits>
using namespace std;

// Resursive Approach
// int minSteps(int n){
//     if(n == 1){
//         return 0;
//     }
//     int op1, op2, op3;
//     op1 = op2 = op3 = INT_MAX;
//     op1 = minSteps(n-1);
//     if(n%2 == 0){
//         op2 = minSteps(n/2);
//     }
//     if(n%3 == 0){
//         op3 = minSteps(n/3);
//     }
//     return min(min(op1, op2), op3) + 1;   
// }

//Top Down DP Approach
int minSteps(int n, int dp[]){
    if(n == 1){
        return 0;
    }
    if(dp[n] != 0){
        return dp[n];
    }
    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;
    op1 = minSteps(n-1, dp);
    if(n%2 == 0){
        op2 = minSteps(n/2, dp);
    }
    if(n%3 == 0){
        op3 = minSteps(n/3, dp);
    }
    return dp[n] = min(min(op1, op2), op3) + 1;   
}

//Bottom Up DP
int minStepsBottom(int n){
    int *dp = new int[n+1]{0};

    dp[1] = 0;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + 1;
        if(i % 2 == 0){
            dp[i] = min(dp[i], dp[i/2] + 1);
        }
        if(i % 3 == 0){
            dp[i] = min(dp[i], dp[i/3] + 1);
        }
    }
    int ans = dp[n];
    delete []dp;
    return ans;

}

int main() {
    int n;
    cin>>n;
    // cout<<minSteps(n);
    int dp[100] = {0};
    cout<<minSteps(n, dp)<<endl;
    cout<<minStepsBottom(n);
    return 0;
}
