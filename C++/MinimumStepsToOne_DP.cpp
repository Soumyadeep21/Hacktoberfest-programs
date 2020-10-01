/*
    Minimum Steps To One

    n ----> 1

    n => n/3    iff n % 3 == 0
    n => n/2    iff n % 2 == 0
    n => n - 1

*/

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// Top Down Approach
int minSteps_TD(int n, int dp[]){

    if(n == 1){
        return 0;
    }

    // If n is already computed
    if(dp[n]!=0){
        return dp[n];
    }

    // if n is not known
    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;

    if(n % 3 == 0){
        op1 = minSteps_TD(n/3, dp);
    }
    if(n % 2 == 0){
        op2 = minSteps_TD(n/2, dp);
    }
    op3 = minSteps_TD(n-1, dp);

    int ans = min(min(op1, op2), op3) + 1;

    return dp[n] = ans;

}

// Bottom Up Approach
int minSteps_BU(int n){
    
    int dp[100] = {0};

    for(int i = 2; i <= n; i++){
        
        int op1, op2, op3;
        op1 = op2 = op3 = INT_MAX;

        if(n % 3 == 0){
            op1 = dp[i/3];
        }
        if(n % 2 == 0){
            op2 = dp[i/2];
        }
        op3 = dp[i-1];

        dp[i] = min(min(op1, op2), op3) + 1;
    }
    return dp[n];
}

int main(){

    int n;
    cin >> n;
    int dp[100] = {0};
    
    cout << minSteps_TD(n, dp) << endl;
    cout << minSteps_BU(n) << endl;

    return 0;
}