#include <bits/stdc++.h>
using namespace std;

// 22

// after sol
// not really understand why we don't need to flush the str
class Solution {
public:
    vector<string> ret;
    int N;
    vector<string> generateParenthesis(int n) {
        N = n;
        func("", 0, 0);
        return ret;
    }
    void func(string str, int left, int right) {
        if(str.length() == N*2) {
            ret.push_back(str);
            return;
        }
        if(left < N) func( str+"(", left+1, right);
        if(right < left) func( str+")", left, right+1);
    }
};