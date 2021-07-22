#include <iostream>
#include <vector>
using namespace std;


// me, just modify some code from 200
class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int& count) {
        
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) 
            return;
        if(grid[i][j] == 2 || grid[i][j] == 0) 
            return;
        
        grid[i][j] = 2; 
        count ++;
        
        dfs(grid, i-1, j, count);
        dfs(grid, i+1, j, count);
        dfs(grid, i, j-1, count);
        dfs(grid, i, j+1, count);
        
        return;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // go through all entries
        // if 1, go dfs, add up island num
        int ret = 0;
        for(int i = 0; i < grid.size(); i ++) {
            for(int j = 0; j < grid[0].size(); j ++) {
                if(grid[i][j] == 1) {
                    int count = 0;
                    dfs(grid, i, j, count);
                    if(count > ret) ret = count;
                }
            }
        }
        return ret;
    }
};