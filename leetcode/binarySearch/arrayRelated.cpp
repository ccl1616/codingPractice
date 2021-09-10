#include <bits/stdc++.h>
using namespace std;

// 153. find the min number
// my sol
class Solution {
public:
    int findMin(vector<int>& nums) {
        sort(nums.begin(), nums.end() );
        return nums[0];
    }
};

// jian, real binary search
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r && nums[l] > nums[r]) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r]) {
                // little number is on the right
                l = m + 1;
            } 
            else {
                // little number is on the left
                r = m;
            }
        }
        return nums[l];
    }
};

// me after sol
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        while(l < r) {
            int m = l + (r - l) / 2;
            if(nums[m] > nums[r]) l = m+1;
            else r = m;
        }
        return nums[l];
    }
};

// ==================================================================
// 33. find index of min number
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(l < r) {
            int m = l + (r - l) / 2;
            if(nums[m] == target) return m;
            else if(nums[m] > target) l = m+1;
            else r = m;
        }
        return nums[l]==target ? l : -1;
    }
};

// sol
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int n = nums.size();
        int lo = 0, hi = n - 1;
        while (lo < hi)
        {
            int mid = lo + (hi - lo)/2;
            //target and mid are on the same side
            if( (nums[mid]-nums[n-1])*(target-nums[n-1]) > 0 ) {
                if(nums[mid] < target)
                    lo = mid + 1;
                else
                    hi = mid;
            }else if(target > nums[n-1])
                hi = mid; // target on the left side
            else
                lo = mid + 1; // target on the right side
        }
        // now hi == lo
        // return nums[lo] == target ? lo : -1;
        if (nums[lo] == target) return lo;
        else return -1;      
    }
};

// me after sol
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(!n) return -1;
        int l = 0;
        int r = n-1;
        while(l < r) {
            int mid = l + (r - l)/2;
            if(nums[mid] == target) return mid;
            // if same sign
            else if( (nums[mid] - nums[n-1])*(target - nums[n-1]) > 0) {
                if(nums[mid] < target) l = mid + 1;
                else r = mid;
            }
            // else divide by general idea
            else if(target > nums[n-1]) r = mid;
            else l = mid + 1;
        }
        return nums[l]==target ? l : -1;
    }
};
