#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        if( !word.size() || !m || !n) return false;

        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                // if board[i][j] == word[0]
                // if dfs can found, ans = true
                if( dfs(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int i, int j, string word, int w) {
        if( i <= 0 || j <= 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[w]) return false;
        if( w == word.size()-1) return true;

        if( board[i][j] == word[w] ) {
            char tmp = board[i][j];
            board[i][j] = ' ';
            bool flag = false;
            if( dfs(board, i-1, j, word, w+1) || dfs(board, i+1, j, word, w+1) ) flag = true;
            if( dfs(board, i, j-1, word, w+1) || dfs(board, i, j+1, word, w+1) ) flag = true;
            board[i][j] = tmp;
            return flag;
        }
        return false;
    }
};