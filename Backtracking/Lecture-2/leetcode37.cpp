class Solution {
public:
    bool isSafe(int r, int c, vector<vector<char>>& board, int n){
        for(int j = 0; j < 9; j++) 
            if(board[r][j] == n+'0') return false;
        for(int j = 0; j < 9; j++) 
            if(board[j][c] == n+'0') return false;
        int sr = (r/3)*3;
        int sc = (c/3)*3;
        for(int i = sr; i < sr+3; i++){
            for(int j = sc; j < sc+3; j++)
                if(board[i][j] == n+'0') return false;
        }
        
        return true;
    }
    bool helper(int r, int c, vector<vector<char>>& board){
        if(r == 9) return true;
        if(c == 9) return helper(r+1, 0, board);
        if(board[r][c] != '.') return helper(r, c+1, board);
        for(int i = 0; i < 9; i++){
            if(isSafe(r, c, board, i+1)){
                board[r][c] = (i+1)+'0';
                bool temp = helper(r, c+1, board);
                if(temp) return true;
                board[r][c] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(0, 0, board);
        return;
    }
};