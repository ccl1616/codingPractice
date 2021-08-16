#include <bits/stdc++.h>
using namespace std;

// 31, next permutation

// ref sol1
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1, k = i, tmp;
        while (i > 0 && nums[i-1] >= nums[i])
            i--;
        for (int j=i; j<k; j++, k--)
            tmp = nums[j], nums[j] = nums[k], nums[k] = tmp;
        if (i > 0) {
            k = i--;
            while (nums[k] <= nums[i])
                k++;
            tmp = nums[i], nums[i] = nums[k], nums[k] = tmp;
        }
    }
};

// sol2
class Solution {
public:
    void nextPermutation(vector<int> &num) 
    {
        if (num.empty()) return;
        
        // in reverse order, find the first number which is in increasing trend (we call it violated number here)
        int i;
        for (i = num.size()-2; i >= 0; --i)
        {
            if (num[i] < num[i+1]) break;
        }
        
        // reverse all the numbers after violated number
        reverse(begin(num)+i+1, end(num));
        // if violated number not found, because we have reversed the whole array, then we are done!
        if (i == -1) return;
        // else binary search find the first number larger than the violated number
        auto itr = upper_bound(begin(num)+i+1, end(num), num[i]);
        // swap them, done!
        swap(num[i], *itr);
    }
};