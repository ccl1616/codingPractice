#include <bits/stdc++.h>
using namespace std;

// DP sol
//wa
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i = 1; i < n; i ++) {
            if(dp[i-1] < i) return false;
            dp[i] = max(dp[i-1], i+nums[i]);
            if(dp[i] >= n-1) return true;
        }
        return ( dp[n-2] >= (n-1) );
    }
    
};

//ac
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n); // size = n
        dp[0] = nums[0];
        if(n == 1) return true; // this is IMPORTANT, ow runtime error
        for(int i = 1; i < n-1; i ++) {
            if(dp[i-1] < i) return false;
            dp[i] = max(dp[i-1], i+nums[i]);
            if(dp[i] >= n-1) return true;
        }
        return ( dp[n-2] >= (n-1) );
    }
    
};
