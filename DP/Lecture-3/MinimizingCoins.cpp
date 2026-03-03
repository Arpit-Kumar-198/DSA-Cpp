/*
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
For example, if the coins are \{1,5,7\} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.
Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c1,c2,....,cn: the value of each coin.
Output
Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print -1.
Constraints

1 <= n <= 100
1 <= x <= 10^6
1 <= ci <= 10^6

Example
Input:
3 11
1 5 7

Output:
3

*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int minimizeCoins(vector<int>& arr,int x, vector<int>& dp){
    
    if (x == 0)
        return 0;

    if(dp[x] != -2)
        return dp[x];
        
    int result = INT_MAX;
    for (int i = 0; i < arr.size(); i++){
        if(x-arr[i] < 0)
            continue;
        result = min(result, minimizeCoins(arr, x - arr[i], dp));
    }
    if(result == INT_MAX) return dp[x] = INT_MAX;
    else
        return dp[x] = 1 + result;
}
int main(){

    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> dp(x+1,-2);
    if(minimizeCoins(arr, x, dp) == INT_MAX)
        cout << -1 << endl;
    else cout << minimizeCoins(arr, x, dp) << endl;
    return 0;
}
