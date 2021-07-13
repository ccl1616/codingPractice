#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// first try, using set
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::set<int> myset;
        for(int i = 0; i < nums.size(); i ++) {
            if( myset.count(nums[i]) ) return nums[i];
            else myset.insert(nums[i]);
        }
        return 0;
    }
};

// using sort
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end() ); // define in <algorithm>
        for(int i = 0; i < nums.size(); i ++) {
            if( nums[i] == nums[i+1]) return nums[i];
        }
        return -1;
    }
};