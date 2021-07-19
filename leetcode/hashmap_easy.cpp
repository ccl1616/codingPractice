#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
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

// 929
// sol
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(string &email : emails) {
            string cleanEmail;
            for(char c : email) {
                if(c == '+' || c == '@') break;
                if(c == '.') continue;
                cleanEmail += c;
            }
            cleanEmail += email.substr(email.find('@'));
            st.insert(cleanEmail);
        }
        return st.size();
    }
};

// me after sol
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> set;
        for(auto i: emails) {
            string cleanEmail;
            for(char c: i) {
                if(c == '+' || c == '@') break; // things after +@ should be ignore
                if(c == '.') continue; // . should be ignore, goes to next iter
                cleanEmail += c;
            }
            cleanEmail += i.substr(i.find('@'));
            set.insert(cleanEmail);
        }
        return set.size();
    }
};

// 387
// sol, 
class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = {0};
        for(int i = 0; i<s.length(); i++)
            count[s[i] - 'a']++;
        
        for(int i = 0; i<s.length(); i++)
            if(count[s[i] - 'a'] == 1)
                return i;
        
        return -1;
    }
};