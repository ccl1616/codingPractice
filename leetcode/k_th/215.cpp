#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// using sort to solve
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};

// using maxheap to solve
int findKthLargest(vector<int>& nums, int k) {
    // O(nlgn) with maxheap
    priority_queue<int> pq; // default max heap 
    for(int i = 0; i < nums.size(); i ++)
        pq.push(nums[i]); // each push require heapify, O(h)
    for(int i = 1; i < k; i ++)
        pq.pop();
    return pq.top();
}