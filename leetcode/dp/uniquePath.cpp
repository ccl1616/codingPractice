// 62, 63
#include <bits/stdc++.h>
using namespace std;

// use math, combination
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1) return 1;
        // (m+n-2)! / (m-1)!(n-1)!
        // n ~ (m+n-2) / (m-1)!
        long long ans = 1;
        for (int i = n; i < (m + n - 1); i++) {
            ans *= i;
            ans /= (i - n + 1);
        }
        return (int)ans;
    }
};

// 63, obstacles exist
// sol1
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[1][1] = 1;
        for(int i = 1; i <= m; i ++) {
            for(int j = 1; j <= n; j ++) {
                if(!obstacleGrid[i-1][j-1]) // ?
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};