#include <bits/stdc++.h>
#include <array>
using namespace std;

// 198. sol dp memo
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
// cleaner
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int prev1 = 0;
        int prev2 = 0;
        for (int num : nums) {
            int tmp = prev1;
            prev1 = max(prev2 + num, prev1);
            prev2 = tmp;
        }
        return prev1;
    }
};

// =======================================
// 213.
/* doesn't work as it is a piece of shit
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int* dp = new int[nums.size() +1];
        dp[0] = nums[nums.size()-1];
        dp[1] = nums[0]; // rob first house
        for(int i = 1; i < nums.size(); i ++) {
            int val = nums[i];
            dp[i+1] = max( dp[i], dp[i-1]+val ); // (i-1) (i) (i+1)
        }
        return dp[nums.size()];
    }
};
*/

// sol1 - jianchao
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if (n < 2) return n ? nums[0] : 0;

        // count the max for [0, n-2], [1, n-1]
        return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
    }
private:
    int robber(vector<int>& nums, int l, int r) {
        int pre = 0, cur = 0;
        for (int i = l; i <= r; i++) {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};