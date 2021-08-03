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