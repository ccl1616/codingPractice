#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int i = 0; 
        int j = 0;
        int m = grid.size();
        int n = grid[0].size();
        int ret = 0;
        cout << m << endl;
        cout << n << endl;
        vector<vector<bool>> vis( m, vector<bool>(n, false));
        for(i ; i < m; i ++) {
            for(j ; j < n; j ++) {
                if(grid[i][j] == 1) {
                    ret = dfs(vis, grid, i, j);
                    return ret;
                }
            }
        }
        
        return ret;
    }

    int dfs(vector<vector<bool>>& vis, vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if( i < 0 || i >= m || j < 0 || j >= n) return 0;
        if(grid[i][j] == 0 || vis[i][j]) return 0;
        vis[i][j] = true;

        int count = 0;
        if( i == 0 ) count ++;
        if( i == m-1) count ++;
        if(j == 0 ) count ++;
        if( j == n-1) count ++;

        // 上
        if(i != 0) {
            if( !grid[i-1][j] ) count ++;
            else count += dfs(vis, grid, i-1, j);
        }
        // 下
        if(i != m-1) {
            if( !grid[i+1][j] ) count ++;
            else  count += dfs(vis, grid, i+1, j);
        }
        // 左
        if(j != 0) {
            if( !grid[i][j-1] ) count ++;
            else count += dfs(vis, grid, i, j-1);
        }
        // 右
        if(j != n-1) {
            if( !grid[i][j+1] ) count ++;
            else count += dfs(vis, grid, i, j+1);
        }
        return count;
    }
};