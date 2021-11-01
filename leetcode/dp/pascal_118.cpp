#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // heap overflow
        /*
        vector<vector<int>> ret;
        if(numRows == 1) {
            vector<int> cur;
            cur.push_back(1);
            ret.push_back(cur);
            return ret;
        }
        vector<int> t;
        t.push_back(1);
        t.push_back(1);
        ret.push_back(t);
        if(numRows == 2) return ret;

        for(int i = 2; i < numRows; i ++) {
            vector<int> cur;
            cur.push_back(1);
            // size = i+1
            // should count 1~i
            for(int j = 1; j <= i; i ++) {
                cur.push_back( ret[i-1][j-1]+ret[i-1][j] );
            }
            cur.push_back(1);
            ret.push_back(cur);
        }
        return ret;
        */
    }
};

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // heap overflow
        /*
        vector<vector<int>> ret;
        if(numRows == 1) {
            vector<int> cur;
            cur.push_back(1);
            ret.push_back(cur);
            return ret;
        }
        vector<int> t;
        t.push_back(1);
        t.push_back(1);
        ret.push_back(t);
        if(numRows == 2) return ret;

        for(int i = 2; i < numRows; i ++) {
            vector<int> cur;
            cur.push_back(1);
            // size = i+1
            // should count 1~i
            for(int j = 1; j <= i; i ++) {
                cur.push_back( ret[i-1][j-1]+ret[i-1][j] );
            }
            cur.push_back(1);
            ret.push_back(cur);
        }
        return ret;
        */
    }
};