#include <bits/stdc++.h>
using namespace std;

// 34
// sol
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/discuss/1347937/Easy-C%2B%2B-Solution-with-only-one-Binary-Search-block
class Solution {
public:
    int BinarySearch(vector<int>& nums, int target, bool firstOccurence)
    {
        int low = 0, high = nums.size()-1, result = -1;
        while(low <= high)
        {
            // int mid = (low + high)/2;
            int mid = low + (high - low)/2;
            if(nums[mid] == target)
            {
                result = mid;
                if(firstOccurence)  high = mid-1;   // If we need to find the first occurence then shrink the searching range towards the left side
                else    low = mid+1;
            }
            else if(nums[mid] < target) low = mid+1;
            else    high = mid - 1;
        }
        return result;
    }
    /*
        first occurence: the first time that the target appears in the array
    */
    vector<int> searchRange(vector<int>& nums, int target) {
        return {BinarySearch(nums,target,true),BinarySearch(nums,target,false)};
    }
};
// after sol, almost same
class Solution {
public:
    int BinarySearch(vector<int>& nums, int target, bool firstOccurence)
    {
        int left = 0;
        int right = nums.size()-1;
        int ret = -1;
        while(left <= right) {
            int mid = left + (right - left)/2;
            if(nums[mid] == target) {
                ret = mid;
                if(firstOccurence) right = mid - 1;
                else left = mid+1;
            }
            else if(nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return ret;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {BinarySearch(nums,target,true),BinarySearch(nums,target,false)};
    }
};