#include <bits/stdc++.h>
using namespace std;

// wa, shitty code 
/*
    TC:
    [1,1,1,1,2,2,2,2]
    2
*/
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        // count the size
        int sum = 0;
        int size = 0;
        int count = 0;
        for(auto x : nums) 
            sum += x;
        if(sum % k != 0) return false;
        size = sum  / k;
        cout << size << endl;

        
        vector<int> arr(k+1, 0);
        int j = 0;
        for(int i = 0; i < k && j < nums.size(); i ++) {
            arr[i] = nums[j];
            nums[j] = 0;

            int cur = arr[i];
            while(cur != size) {
                int tmp = find(nums, size-cur);
                if(tmp == -1) return false;
                else {
                    cur += nums[tmp];
                    nums[tmp] = 0;
                }
            }
            while(nums[j] == 0 && j < nums.size()) j ++;  
            count ++;
        }
        return (count == k);
    }

    int find(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i ++) {
            if(nums[i] <= target) {
                return i;
            }
        }
        return -1;
    }
};

// after back to back SWE
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        int size = 0;
        for(auto x:nums) 
            sum += x;
        size = sum / k; // entry size
        // if the sum cannot be partioned, false
        if( k == 0 || (sum % k ) != 0 || nums.size() == 1 ) return false;

        // set up recorder
        vector<bool> used(nums.size(), false);
        return backtrack(nums, used, k, 0, 0, size);
    }

    bool backtrack(vector<int>& nums, vector<bool>& used, int k, int start, int cur, int size) {
        if(k == 1) return true; // won't count the last bucket 
        if(cur == size) return backtrack(nums, used, k-1, 0, 0, size); // done one bucket!go for next iteration
        for(int i = start; i < nums.size(); i ++) {
            if(!used[i]) {
                used[i] = true;
                if( backtrack(nums, used, k, i+1, cur+nums[i], size)) return true;
                used[i] = false; // if this cannot be used, we should put it back
            }
        }
        return false;
    }
};
