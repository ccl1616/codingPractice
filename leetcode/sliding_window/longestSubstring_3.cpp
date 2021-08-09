#include <bits/stdc++.h>
using namespace std;

// 3.
// me after sol
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // key: use window to frame the current string
        int size = 0;
        int start = 0;
        int end = 0;
        set<int> S;
        int n = s.length();
        
        while(end < n) {
            // not in set
            if(S.find(s[end]) == S.end()) {
                S.insert(s[end]);
                size = max(size, end-start+1);
                end ++;
            }
            // in set
            else {
                S.erase(s[start]); // delete front
                start ++;
            }
        }
        return size;
    }
};