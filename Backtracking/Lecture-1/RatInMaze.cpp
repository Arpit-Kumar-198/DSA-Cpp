/*
    Given a n x n binary matrix
    0 -> open cell and 1 -> closed cell
    A rat starts from top left corner and wants to come reach bottom right corner of maze 
    Find total number of ways 

INPUT:
7
0 0 1 0 0 1 0
1 0 1 1 0 0 0
0 0 0 0 1 0 1
1 0 1 0 0 0 0
1 0 1 1 0 1 0
1 0 0 0 0 1 0
1 1 1 1 0 0 0 

OUTPUT:
4
*/
#include<bits/stdc++.h>
using namespace std;
bool canGo(int i, int j, int n, vector<vector<int>>& maze){
    if(i >= 0 && i < n && j >= 0 && j < n && maze[i][j] == 0) return true;
    return false;
}
int totalWays(vector<vector<int>>& maze, int sr, int sc){
    if(sr < 0 || sc < 0) return 0;
    if(sr == maze.size()-1 && sc == maze.size()-1) return 1;

    maze[sr][sc] = 2; // It means this cell is visited
    int ways = 0;

    // down ways
    if (canGo(sr+1, sc, maze.size(), maze))
        ways += totalWays(maze, sr + 1, sc);
    // right ways
    if (canGo(sr, sc+1, maze.size(), maze))
        ways += totalWays(maze, sr, sc+1);
    // up ways
    if (canGo(sr-1, sc, maze.size(), maze))
        ways += totalWays(maze, sr - 1, sc);
    // left ways
    if (canGo(sr, sc-1, maze.size(), maze))
        ways += totalWays(maze, sr, sc-1);

    maze[sr][sc] = 0;
    return ways;
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> maze(n, vector<int> (n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) cin >> maze[i][j];
    }
    cout << totalWays(maze, 0, 0);
}