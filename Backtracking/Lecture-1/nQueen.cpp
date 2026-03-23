#include<bits/stdc++.h>
using namespace std;
bool canPlaceQueen(int row, int col, int n, vector<vector<char>>& grid){
    // column check
    for (int i = row - 1; i >= 0; i--){
        if(grid[i][col] == 'Q') return false;
    }
    // left diagonal check 
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
        if(grid[i][j] == 'Q') return false;
    }
    // right diagonal check 
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
        if(grid[i][j] == 'Q') return false;
    }
    return true;
}
void helper(int row , int n, vector<vector<char>>& grid,vector<vector<string>>& res){
    if(row == n){
        vector<string> v;
        for (int i = 0; i < n; i++)
        {
            string temp = "";
            for (int j = 0; j < n; j++) {
                temp += grid[i][j];
                temp += " ";
            }
            v.push_back(temp);
        }
        res.push_back(v);
        return;
    }
    for (int col = 0; col < n; col++){
        if(canPlaceQueen(row, col, n, grid)){
            grid[row][col] = 'Q';
            helper(row + 1, n, grid, res);
            grid[row][col] = '.';
        }
    }
    return;
}
vector<vector<string>> nQueen(int n){
    vector<vector<char>> grid(n, vector<char>(n, '.'));
    vector<vector<string>> res;
    helper(0, n, grid, res);
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<vector<string>> ans = nQueen(n);
    for(auto v : ans){
        for(auto str : v)
            cout << str << endl;
        cout << endl;
    }
    cout << "Total Possible Solutions : " << ans.size() << endl;
    return 0;
}