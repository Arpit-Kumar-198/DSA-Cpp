/*
Word Search:

Given an M x N grid of characters board and a string word, determine whether the word exists in the board.

The word can be formed by sequentially adjacent cells, where:

1. Adjacent cells are horizontally or vertically neighboring.
2. Each cell can be used only once per path.

Return "True" if the word exists in the board, otherwise return "False".

Input Format
First line: Two integers M and N.
Next M lines: Each line contains N space-separated characters.
Last line: A string word.

Output Format
Return "Word exist" or "Word does not exist" as a string.

Constraint
M = board.length
N = board[i].length
1 <= M, N <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.

Sample Input:
3 4
ABCE
SFCS
ADEE
ABCCED

Sample Output:
True

Explanation:
Start from the top-left area of the grid and try to form the word step by step by moving to adjacent cells.

*/
#include<bits/stdc++.h>
using namespace std;
bool helper(vector<vector<char>>& board, int i, int j, int m, int n, string word, int idx){
    if(idx == word.size()) return true;
    if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '#' || board[i][j] != word[idx]) return false;

    bool ans = false;
    char ch = board[i][j];
    board[i][j] = '#';

    // go up
    ans = ans || helper(board, i-1, j, m, n, word, idx + 1);
    // go right
    ans = ans || helper(board, i, j+1, m, n, word, idx + 1);
    // go down
    ans = ans || helper(board, i+1, j, m, n, word, idx + 1);
    // go left
    ans = ans || helper(board, i, j-1, m, n, word, idx + 1);

    board[i][j] = ch;
    return ans;
}
bool wordExist(vector<vector<char>>& board, int m, int n, string word){
    bool ans = false;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(board[i][j] == word[0])
                ans = ans || helper(board, i, j, m, n, word, 0);
        }
    }
    return ans;
}
int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<char>> board(m, vector<char>(n, '#'));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) cin >> board[i][j];
    }
    string word;
    cin >> word;

    if(wordExist(board, m, n, word)) cout << "Word exist";
    else cout << "Word does not exist";
}