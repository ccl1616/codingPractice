
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <unordered_map>
  
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        vector<vector<int>> ret;
        //put them into pq
        for(int i = 0; i < nums1.size(); i ++) {
            for(int j = 0; j < nums2.size(); j ++) {
                int sum = nums1[i]+nums2[j];
                if(pq.size() < k)
                    pq.push( { sum, {nums1[i], nums2[j]} } );
                else if(sum < pq.top().first) {
                    pq.pop();
                    pq.push( { sum, {nums1[i], nums2[j]} } );
                }
            }
        }
        // take them out
        while( !pq.empty() ) {
            ret.push_back( { pq.top().second.first, pq.top().second.second} );
            pq.pop();
        }
        reverse(ret.begin(), ret.end() );
        return ret;
    }
};