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

// after sol
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>arr = {{}};
        
        
    }
};