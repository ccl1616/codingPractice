#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// using sort to solve
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};

// using queue to solve
