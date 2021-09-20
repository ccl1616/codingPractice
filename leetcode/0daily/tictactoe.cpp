#include <bits/stdc++.h>
using namespace std;

// WA
class Solution {
public:
    vector<vector<int>> board;
    string tictactoe(vector<vector<int>>& moves) {
        for(int i = 0; i < 3; i ++) {
            vector<int> inner;
            inner.push_back(0);
            inner.push_back(0);
            inner.push_back(0);
            
            board.push_back(inner);
        }
        
        for(int i = 0; i < moves.size(); i ++) {
            int x = moves[i][0];
            int y = moves[i][1];
            board[x][y] = (i%2);
            int winner = wins();
            if( winner != -1) {
                if(winner == 0) return "A";
                else if(winner = 1) return "B";
            }
        }
        return (moves.size() == 3*3) ?"Draw" :"Pending";
    }
    int wins() {
        if(board[0][0] == board[0][1] && board[0][1] == board[0][2]) return board[0][0];
        if(board[1][0] == board[1][1] && board[1][1] == board[1][2]) return board[1][0];
        if(board[2][0] == board[2][1] && board[2][1] == board[2][2]) return board[2][0];

        if(board[0][0] == board[1][0] && board[1][0] == board[2][0]) return board[0][0];
        if(board[0][1] == board[1][1] && board[1][1] == board[2][1]) return board[0][1];
        if(board[0][2] == board[1][2] && board[1][2] == board[2][2]) return board[0][2];

        if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return board[0][0];
        if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) return board[0][2];

        return -1;
    }
};

// AC, record by player
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> A(8,0), B(8,0);
        /*
        [0] [1] [2] row
        [3] [4] [5] col
        [6] left-top to right-down
        [7] right-top to left-down
        */

        // record A and B seperatly
        for(int i = 0; i < moves.size(); i ++) {
            int r = moves[i][0];
            int c = moves[i][1];
            if( !(i % 2) ) {
                A[r] ++;
                A[3 + c] ++;
                if(r == c) A[6] ++;
                if(r == 2-c) A[7] ++;
            }
            else{
                B[r] ++;
                B[3 + c] ++;
                if(r == c) B[6] ++;
                if(r == 2-c) B[7] ++;
            }
        }    
        for(int i = 0; i < 8; i ++) {
            if(A[i] == 3) return "A";
            if(B[i] == 3) return "B";
        }
        return moves.size() == 3*3 ?"Draw" :"Pending";
    }
};