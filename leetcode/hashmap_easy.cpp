#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace  std;

// 349
// my first try, use 2 maps
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_map<int, int> map;
        unordered_map<int, int> map2;
        for(auto x: nums1) {
            if(!map.count(x)) map[x] = 1;
        }
        for(auto i: nums2) {
            if(map.count(i) && !map2.count(i)) {
                ret.push_back(i);
                map2[i] = 1;
            }
        }
        return ret;
    }
};

// me using 1 map, but the memory seems same
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_map<int, int> map;
        for(auto x: nums1) {
            if(!map.count(x)) map[x] = 1;
        }
        for(auto i: nums2) {
            if(map.count(i) ) {
                if(map[i]) {
                    ret.push_back(i);
                    map[i] = 0;
                }
            }
        }
        return ret;
    }
};