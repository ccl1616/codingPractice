#include <bits/stdc++.h>
using namespace std;
// 1006

// self sol
/*
    find : O(nlogn)
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        set<int> S;
        vector<int> ret;
        for(int i = 0; i < n; i ++) {
            if(S.find(nums[i]) == S.end()) S.insert(nums[i]); 
            else ret.push_back(nums[i]);
        }
        return ret;
    }
};

// sol, O(n)
/*
    idea: put nums[i] into slotID = nums[i]-1
    i:      0   1   2   3
    val:    1   2   3   4

    then check, if val-1 != id -> wrong
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;
        int i = 0;
        while( i < n) {
            if(nums[i] != nums[ nums[i]-1 ]) swap(nums[i], nums[ nums[i]-1 ]);
            else i ++;
        }
        for(int i = 0; i < n; i ++) {
            if(nums[i]-1 != i) ret.push_back(nums[i]);
        }
        return ret;
    }
};