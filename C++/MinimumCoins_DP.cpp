#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

// Top Down Approach
int minCoins_TD(int n, int coins[], int t, int dp[]){

    if(n == 0){
        return 0;
    }

    if(dp[n] != 0){
        return dp[n];
    }

    int ans = INT_MAX;
    
    for(int i = 0; i < t; i++){
        if(n - coins[i] >= 0){
            int subprob = minCoins_TD(n - coins[i], coins, t, dp);
            ans = min(ans, subprob + 1);
        }        
    }

    return dp[n] = ans;

}

// Bottom Up Approach
int minCoins_BU(int n, int coins[], int t){
     
    int dp[100] = {0};

    for(int i = 1; i <= n; i++){
        dp[i] = INT_MAX;
        for(int j = 0; j < t; j++){
            if(i-coins[j] >= 0){
                int subprob = dp[i - coins[j]];
                dp[i] = min(dp[i], subprob + 1);
            }
        }
    }

    return dp[n];

}

int main(){

    int n;
    int t;
    int coins[10];

    cout << "Enter the Amount" << endl;    
    cin >> n;
    cout << "Enter the number of coins" << endl;    
    cin >> t;    
    cout << "Enter the coins" << endl;
    for(int i = 0; i < t; i++){
        cin >> coins[i];
    }

    int dp[100] = {0};

    cout << "The minimum no. of coins are: " << endl;
    cout << minCoins_TD(n, coins, t, dp) << endl;
    cout << minCoins_BU(n, coins, t) << endl;

    return 0;
}