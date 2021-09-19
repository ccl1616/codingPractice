#include <bits/stdc++.h>
using namespace std;
// 115, use dp
// https://leetcode.com/problems/distinct-subsequences/discuss/37316/7-10-lines-C%2B%2B-Solutions-with-Detailed-Explanations-(O(m*n)-time-and-O(m)-space)
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<unsigned int>> dp(m + 1, vector<unsigned int> (n + 1, 0));
        for(int i = 0; i <= n; i ++) dp[0][i] = 1;
        for(int j = 1; j <= n; j ++) {
            for(int i = 1; i <= m; i ++) {
                dp[i][j] = dp[i][j-1] + (s[j-1] == t[i-1] ?dp[i-1][j-1] :0);
            }
        }
        return dp[m][n];
        
        
        // int m = t.size();
        // int n = s.size();
        // vector<vector<unsigned int>> dp(m + 1, vector<unsigned int> (n + 1, 0));
        // for(int i = 0; i <= n; i ++) dp[0][i] = 1;
        // for(int j = 1; j <= n; j ++)
        //     for(int i = 1; i <= m; i ++)
        //         dp[i][j] = dp[i][j-1] + (t[i-1] == s[j-1] ?dp[i-1][j-1] :0);
        // return dp[m][n];
    }
};