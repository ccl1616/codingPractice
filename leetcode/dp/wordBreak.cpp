#include <bits/stdc++.h>
using namespace std;

// 139
// me after sol
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size(), false);
        dp[0] = true;
        for(int i = 0 ; i < s.size(); i ++) {
            // dp[i] : [0, i-1] can be founded in Dict
            if(dp[i]) {
                // then check next sub string
                for(auto x: wordDict) {
                    int tail = i + x.size() -1; // position of this Dict word
                    // if the tail is out of bound -> impossible
                    // if x = substring -> gotcha
                    if(tail < s.size() && x == s.substr(i, x.size()) ){
                        // if tail is at the end of s -> the end
                        if(tail == s.size()-1 ) return true;
                        // else record tail in dp
                        else {
                            dp[tail+1] = true;
                            // break; this would cause error ! because we need to iterate through the wordDict
                        }
                    }
                }
            }
        }
        return false;
    }
};