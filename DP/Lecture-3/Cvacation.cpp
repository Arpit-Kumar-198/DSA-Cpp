/*
    Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.
    The vacation consists of N days. For each i (1 <= i <= N) Taro will choose one of the following activities and do it on the i-th day:
    A: Swim in the sea. Gain ai points of happiness.
    B: Catch bugs in the mountains. Gain bi points of happiness.
    C: Do homework at home. Gain ci points of happiness.

    As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

    Find the maximum possible total points of happiness that Taro gains.

    1 <= N <= 10^5
    1 <= ai, bi, ci <= 10^4

    Input : 3
            10 40 70
            20 50 80
            30 60 90
            
    Output : 210

*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(3, 0));
    int a, b, c;
    cin >> a >> b >> c;

    dp[0][0] = a;
    dp[0][1] = b;
    dp[0][2] = c;

    int res = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> c;
        dp[i][0] = a + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = b + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = c + max(dp[i - 1][0], dp[i - 1][1]);
    }
    cout << max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
    return 0;
}