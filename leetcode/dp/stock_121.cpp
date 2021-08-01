#include <bits/stdc++.h>
using namespace std;

// WA
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size()) return 0;
        int min = 0;
        int max = 0;
        for(int i = 1; i < prices.size(); i ++) {
            int cur = prices[i];
            if(cur < prices[min] && !max) {
                min = i;
                max = i;
            }
            else if(cur > prices[max]) max = i;
        }
        if(max > min) return prices[max]-prices[min];
        else return 0;
    }
};

// after sol, Kadane, non-dp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP = INT_MAX; // get min entry
        int maxP = 0; // save max profit
        for(int i = 0; i < prices.size(); i ++) {
            minP = min(minP, prices[i]);
            maxP = max(maxP, prices[i]-minP);
        }
        return maxP;
    }
};

// sol dp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size(), 0); // max profit on day i-th
        int min_price = prices[0];
        for(int i = 1; i < prices.size(); i ++) {
            dp[i] = max( dp[i-1], prices[i]-min_price ); // profit from prev day OR profit from today
            min_price = min(min_price, prices[i]);
        }
        return dp[prices.size()-1];
    }
};


// ================================================================
// 122
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size(), 0); // max profit on day i-th
        int min_price = prices[0];
        for(int i = 1; i < prices.size(); i ++) {
            dp[i] = max( dp[i-1], prices[i]-min_price ); // profit from prev day OR profit from today
            min_price = min(min_price, prices[i]);
        }
        return dp[prices.size()-1];
    }
};