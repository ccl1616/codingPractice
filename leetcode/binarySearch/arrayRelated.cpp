#include <bits/stdc++.h>
using namespace std;

// 153.
// my sol
class Solution {
public:
    int findMin(vector<int>& nums) {
        sort(nums.begin(), nums.end() );
        return nums[0];
    }
};

// jian
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r && nums[l] > nums[r]) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return nums[l];
    }
};