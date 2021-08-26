#include <bits/stdc++.h>
using namespace std;

// 130, after sol AC
class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col, int m, int n) {
        if(row < 0 || row >= m || col < 0 || col >= n) return;
        if(board[row][col] != 'O') return;
        // mark the margins as Q
        board[row][col] = 'Q';
        dfs(board, row-1, col, m , n);
        dfs(board, row+1, col, m , n);
        dfs(board, row, col-1, m , n);
        dfs(board, row, col+1, m , n);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        // dfs for all boundary connected
        // vertical 
        for(int i = 0; i < m; i ++) {
            if(board[i][0] == 'O') 
                dfs(board, i, 0, m, n);
            if(board[i][n-1] == 'O') 
                dfs(board, i, n-1, m, n);
        }
        // horizontal
        for(int j = 0; j < n; j ++) {
            if(board[0][j] == 'O')
                dfs(board, 0, j, m, n);
            if(board[m-1][j] == 'O')
                dfs(board, m-1, j, m, n);
        }
        // deal with all the leftovers
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'Q') board[i][j] = 'O';
            }
        }
        return;
    }
};
