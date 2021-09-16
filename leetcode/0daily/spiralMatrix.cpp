#include <bits/stdc++.h>
using namespace std;
// 54
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if (matrix.size() == 0) return ret;

        // right, down, left, up
        int x[4] = {0, 1, 0, -1 };
        int y[4] = {1, 0, -1, 0};
        int i = 0; 
        int j = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int pattern = 0;

        int visited = -1000;
        while(ret.size() != matrix.size()*matrix[0].size() ) {
            // must be true
            ret.push_back(matrix[i][j]);
            matrix[i][j] = visited;

            // modify by pattern
            int next_i = i + x[pattern];
            int next_j = j + y[pattern];


            // check
            if( next_i >= 0 && next_i < row && next_j >= 0 && next_j < col && matrix[next_i][next_j] != visited) {
                i = next_i;
                j = next_j;
            }
            else {
                pattern = (pattern + 1) % 4;
                i += x[pattern];
                j += y[pattern];
            }
        }

        return ret;
    }
};

