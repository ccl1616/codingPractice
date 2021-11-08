#include <bits/stdc++.h>
using namespace std;
//1108 daily

// recursive
class Solution {
public:
    int numTrees(int n) {
        if(n <= 1) return 1;
        int ans = 0;
        for(int i = 1; i <= n; i++) 
            ans += numTrees(i-1) * numTrees(n-i);
        return ans;
    }
};

// recursive to memoized
class Solution {
public:
    int dp[20]{};
    int numTrees(int n) {
        if(n <= 1) return 1;
        if(dp[n] != 0) return dp[n];
        
        // let every i be root once
        for(int i = 1; i <= n; i++) 
            dp[n] += numTrees(i-1) * numTrees(n-i);
        return dp[n];
    }
};

// iterative
class Solution {
public:
    int dp[20]{};
    int numTrees(int n) {
        dp[0] = dp[1] = 1;
        for(int j = 2; j <= n; j ++) {
            // let every i be root once
            for(int i = 1; i <= j; i ++) 
                dp[j] += dp[i-1] * dp[j-i];
        }
        return dp[n];
    }
};