
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <unordered_map>
  
using namespace std;

// sol, so good, learn a lot
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int>mp;
        vector<int> res;

        // first, put them all into map
        for(int i=0;i<nums.size();i++)
            mp[nums[i]] += 1;      
        
        // build pq by freq, num
        for (auto i : mp)
            pq.push(make_pair(i.second, i.first));
        
        // pq sort big->small by default, so the top would be big freq
        for(int i=0;i<k;i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};