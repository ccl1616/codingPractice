#include <bits/stdc++.h>
using namespace std;

// 283
// sol1
// brutal force, after official sol
// faster than 89%
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // count the zeros
        int size = nums.size();
        int zero_count = 0;
        vector<int> ret;
        for(int i = 0; i < size; i ++){
            if(nums[i] == 0) zero_count ++;
            else ret.push_back(nums[i]);
        }
        // push back zeros
        while(zero_count--) 
            ret.push_back(0);
        
        for(int i = 0; i < size; i ++) 
            nums[i] = ret[i];
        
    }
};