#include <bits/stdc++.h>
using namespace std;
// 509. easy, simple fib

// sol1 basic
class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        return fib(n-1) + fib(n-2);
    }
};

// sol2 dp
class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i ++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};