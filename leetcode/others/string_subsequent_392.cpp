#include <bits/stdc++.h>
using namespace std;

// 392
// myself
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_pt = 0;
        for(int i = 0; i < t.size(); i ++) {
            if(t[i] == s[s_pt]) 
                s_pt ++;
        }
    
        // if(s_pt == s.length()-1) return true; //stupid bug!!
        if(s_pt == s.length()) return true;
        else return false;
    }
};
