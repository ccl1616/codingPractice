#include <bits/stdc++.h>
using namespace std;


// 209.
// sol, sliding window
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int windowSum = 0, windowStart = 0;
        int minWindowSize = numeric_limits<int>::max();

        for(int windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
            windowSum += nums[windowEnd];

            // 如果 subarray sum >= s，那就開始縮減 subarray
            while(windowSum >= target) {
                minWindowSize = min(minWindowSize, windowEnd-windowStart+1);
                windowSum -= nums[windowStart];
                windowStart++;
            }
        }

        return minWindowSize == numeric_limits<int>::max() ? 0 : minWindowSize;
    }
};