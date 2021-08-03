#include <bits/stdc++.h>
using namespace std;

// 322.
// dp[i]: minimum #coins for $i
// back to SWE, bottom-up
// vector version
class Solution {
public:
    int change(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i ++) {
            for(int j = 0; j < coins.size(); j ++) {
                if(coins[j] <= i) {
                    int id = i - coins[j];
                    if(dp[id] == amount+1) break;
                    dp[i] = min(dp[id]+1, dp[i]);
                }
            }
        }
        return dp[amount] > amount ?-1:dp[amount];
    }
};

// array version, cause vector is slower than array
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // vector<int> dp(amount+1, amount+1);
        int k = amount +1;
        int dp[k];
        dp[0] = 0;
        for(int i = 1; i <= amount; i ++) {
            dp[i] = amount+1;
            for(int j = 0; j < coins.size(); j ++) {
                if(coins[j] <= i) {
                    int id = i - coins[j];
                    if(dp[id] != amount+1) dp[i] = min(dp[id]+1, dp[i]);
                }
            }
        }
        return dp[amount] > amount ?-1:dp[amount];
    }
};

// ====================================================================================
// 518
/*
    dp[i] = #combination of $i
*/
// 2D
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int dp[n+1][amount+1];
        dp[0][0] = 1;
        for(int i = 1; i <= amount; i ++) dp[0][i] = 0;
        for(int i = 1; i <= n; i ++) dp[i][0] = 1;

        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= amount; j ++) {
                // don't use this coin + use this coin
                if(coins[i-1] <= j)
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][amount];
    }
};

// 1D
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0)
            return 1;
        // if(coins.size() == 0)
        //     return 0;
        // vector<int> dp(amount + 1, 0);
        int dp[amount+1];
        dp[0] = 1;
        for(int i = 0; i < coins.size(); ++ i){
            for(int j = coins[i]; j <= amount; ++ j){
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};