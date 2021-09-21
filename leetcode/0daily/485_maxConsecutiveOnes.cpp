#include <bits/stdc++.h>
using namespace std;

// AC, self
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int* dp;
        dp = new int[nums.size()];
        dp[0] = nums[0] == 1 ?1 :0;
        int ret = dp[0];
        for(int i = 1; i < nums.size(); i ++) {
            if(nums[i] == 1) {
                dp[i] = dp[i-1]+1;
                if(dp[i] > ret) ret = dp[i];
            }
            else {
                dp[i] = 0;
            }
        }
        return ret;
    }
};

// sol, not faster but save space
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur = 0;
        int ret = 0;
        for(auto x : nums) {
            if(x == 1) {
                cur ++;
                ret = max(ret, cur);
            }
            else cur = 0;
        }
        return ret;
    }
};