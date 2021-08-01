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

// after sol
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