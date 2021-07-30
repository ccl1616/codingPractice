#include <bits/stdc++.h>
using namespace std;

// 53. kadane's algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        int cur = nums[0];
        for(int i = 1; i < nums.size(); i ++) {
            cur = max(nums[i], cur+nums[i]);
            if(cur > ret) ret = cur;
        }
        return ret;
    }
};