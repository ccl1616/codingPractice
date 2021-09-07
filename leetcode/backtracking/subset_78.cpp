#include <bits/stdc++.h>
using namespace std;

// 78
// jianchao, iterative solution
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> arr = { {} };
        for(int x: nums ){
            int n = arr.size();
            for(int i = 0; i < n; i ++) {
                arr.push_back(arr[i]);
                arr.back().push_back(x);
            }
        }
        return arr;
    }
};

// sol, backtracking
class Solution {
public:
    vector<vector<int>> ans;
    
    void sub(vector<int> &nums, int i, vector<int> temp)
    {
        if(i == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
        sub(nums, i+1, temp);
        temp.push_back(nums[i]);
        sub(nums, i+1, temp); // backtracking
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;       
        sub(nums, 0, temp); // or sub(nums, 0, vector<int> {});
        return ans;
    }
};

// backtracking, after sol
class Solution {
public:
    vector<vector<int>> ans;
    
    void bt(vector<int> &nums, int i, vector<int> temp)
    {
        // base case
        if(i == nums.size()) {
            ans.push_back(temp);
            return;
        }
        // don't-add or add
        bt(nums, i+1, temp);
        temp.push_back(nums[i]);
        bt(nums, i+1, temp);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;       
        bt(nums, 0, temp); 
        return ans;
    }
};