#include <bits/stdc++.h>
using namespace std;

// 198
class Solution {
public:
    int rob(vector<int>& nums) {
        // dp[i] saves best sol for i houses
        if(nums.size() == 0) return 0;
        int* dp = new int[nums.size() +1];
        dp[0] = 0;
        dp[1] = nums[0]; // rob first house
        for(int i = 1; i < nums.size(); i ++) {
            int val = nums[i];
            /*
                dp[i+1]: best sol for i+1 
                dp[i]:   best for i
                dp[i-1]: best for i-1
                val: val of house i
                dp[i-1] + val = i house should be rob
            */
            dp[i+1] = max( dp[i], dp[i-1]+val ); // (i-1) (i) (i+1)
        }
        return dp[nums.size()];
    }
};
