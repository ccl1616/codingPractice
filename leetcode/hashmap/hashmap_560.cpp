#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace  std;

// sol
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> seen = {{0, 1}};
        int count = 0, sum = 0;
        for (auto n: nums) {
            sum += n;
            count += seen[sum - k];
            seen[sum]++;
        }
        return count;
    }
};
// https://leetcode.com/problems/subarray-sum-equals-k/discuss/431725/C%2B%2B-Performant-Solution-Explained-~100-Time-~95-Space