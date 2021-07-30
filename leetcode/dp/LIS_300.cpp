// longest increasing subsequence
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// practice
// non-decreasing subsequence
vector<int> sol(vector<int> nums) {
    vector<int> table;
    table.push_back(1);
    for(int j = 1; j < nums.size(); j ++) {
        table.push_back(1);
        for(int i = 0; i < table.size() && i != j; i ++) {
            if(nums[j] >= nums[i] && table[i] >= table[j]) {
                table[j] = table[i]+1;
            }
        }
    }
    return table;
}

int main() {
    vector<int> arr{-1, 3, 4, 5 ,2, 2, 2, 2};
    vector<int> ret = sol(arr);
    for(auto x: ret)
        cout << x << " ";
    cout << endl;
}
// ==================================================================

// 300, O( n^2 )
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int max = 1;
        vector<int> table;
        table.push_back(1);
        for(int j = 1; j < nums.size(); j ++) {
            table.push_back(1);
            for(int i = 0; i < table.size() && i != j; i ++) {
                if(nums[j] > nums[i] && table[i] >= table[j]) {
                    table[j] = table[i]+1;
                    if(table[j] > max) max = table[j];
                }
            }
        }
        return max;
    }
};

// sol, O( nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        res.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i ++) {
            // get the num that is greater than nums[]
            auto it = lower_bound(res.begin(), res.end(), nums[i]);
            if(it == res.end()) res.push_back(nums[i]);
            else *it = nums[i];
        }
        return res.size();
    }
};