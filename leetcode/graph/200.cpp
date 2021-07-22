#include <iostream>
#include <vector>
using namespace std;

// sol
class Solution {
public:
    void DFS(vector<vector<char>>& grid, int i, int j) {
        // boundary checking
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        // return if current position is of water or is already visited
        if(grid[i][j] == '2' || grid[i][j] == '0')
            return;
        
        // mark the current as visited
        grid[i][j] = '2';
        
        // do DFS in all 4 directions
        DFS(grid, i+1, j);
        DFS(grid, i, j-1);
        DFS(grid, i-1, j);
        DFS(grid, i, j+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // We can treat the matrix grid as a grid. Each Island is a
        // connected component. The task is to find no. of disconnectedd components
        // in the graph.
        
        int islands = 0;
        // We make each 1 as 2 in when it is visited
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                // do DFS in case has not been visited and there is land
                if(grid[i][j] == '1') {
                    DFS(grid, i, j);
                    ++islands;
                } 
            }
        }
        return islands;
    }
};

// me after sol, RE, heap overflow; corrected
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // if(i < 0 || j < 0 || i >= grid[0].size() || j >= grid[0].size()) // wrong here
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) // correct
            return;
        if(grid[i][j] == '2' || grid[i][j] == '0') return;
        
        grid[i][j] = '2';
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
        
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // go through all entries
        // if 1, go dfs, add up island num
        int ret = 0;
            for(int i = 0; i < grid.size(); i ++) {
                for(int j = 0; j < grid[0].size(); j ++) {
                    if(grid[i][j] == '1') {
                        dfs(grid, i, j);
                        ret ++;
                    }
                }
            }
        return ret;
    }
};