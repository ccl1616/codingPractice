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
        vector<vector<int>> ret(numRows);
        for(int i = 0; i < numRows; i ++) {
            ret[i].resize(i+1);
            ret[i][0] = 1;
            ret[i][i] = 1;
            for(int j = 1; j < i; j ++)
                ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
        }
        return ret;
    }
};

// 119. get roeIndex pascal
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> ret(rowIndex+1);
        vector<int> prev(rowIndex+1);
        for(int i = 0; i <= rowIndex; i ++) {
            ret[0] = 1;
            ret[i] = 1;
            // we can't do it by incremental, since the value would be polluted!
            // for(int j = 1; j < i; j ++)
            //     ret[j] = ret[j] + ret[j-1];
            for(int j = i-1; j > 0; j --)
                ret[j] = ret[j] + ret[j-1];
        }
        return ret;
    }
};