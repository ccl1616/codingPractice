#include <bits/stdc++.h>
using namespace std;

// self, ac, but ugly
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_map<int, int> map;
        if(nums1.size() < nums2.size()) {
            for(auto x : nums2) {
                if(!map.count(x)) map[x] = 1;
                else map[x]++;
            }
            for(auto i : nums1) {
                if(map.count(i)) {
                    if(map[i]) {
                        ret.push_back(i);
                        map[i] --;
                    }
                }
            }
        }
        else {
            for(auto x : nums1) {
                if(!map.count(x)) map[x] = 1;
                else map[x]++;
            }
            for(auto i : nums2) {
                if(map.count(i)) {
                    if(map[i]) {
                        ret.push_back(i);
                        map[i] --;
                    }
                }
            }
        }
        
        return ret;
    }
};