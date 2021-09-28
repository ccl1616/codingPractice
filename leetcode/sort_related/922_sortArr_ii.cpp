#include <bits/stdc++.h>
using namespace std;
// 0928 daily
// ac but dumb
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        stack<int> even;
        stack<int> odd;
        for(auto x: nums) {
            if(x%2 == 0) even.push(x);
            else odd.push(x);
        }
        for(int i = 0; i < nums.size(); i ++) {
            if(i%2 == 0) {
                nums[i] = even.top();
                even.pop();
            }
            else {
                nums[i] = odd.top();
                odd.pop();
            }
        }
        return nums;
    }
};

// two pointer, way more smarter
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        for( int i = 0, j = 1; i < nums.size(), j < nums.size(); i += 2, j += 2) {
            while(i < nums.size() && !(nums[i] % 2)) i += 2; // find odd num
            while(j < nums.size() && (nums[j] % 2) ) j += 2; // find even num
            if(i < nums.size() && j < nums.size() ) swap(nums[i], nums[j]);
        }
        return nums;
    }
};