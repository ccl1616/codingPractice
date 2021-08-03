#include <bits/stdc++.h>
using namespace std;

// dp[i]: minimum #coins for $i

// back to SWE, bottom-up
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(coins.size(), amount+1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i ++) {
            for(int j = 0; j < coins.size(); j ++) {
                if(coins[j] < i) {
                    int id = i - coins[j];
                    dp[i] = min(dp[id]+1, dp[i]);
                }
            }
        }
        return dp[amount] > amount ?-1:dp[amount];
    }
};