#include <bits/stdc++.h>
#include<string>
using namespace std;
int mod = 1e9+7;
int numTarget(int n, int k, int tgt, vector<vector<int>>& dp)
{
    if(n == 0 && tgt > 0)
        return 0;
    if(n == 0 && tgt == 0)
        return 1;
    if(dp[n][tgt] != -1)
        return dp[n][tgt];
    int res = 0;

    for (int j = 1; j <= k; j++){
        if(tgt-j >= 0) res = (res%mod + numTarget(n - 1, k, tgt - j, dp)%mod)%mod;
    }
    
    return dp[n][tgt] = res;
}
int main() {
    int n, k, tgt;
    cin >> n >> k >> tgt;
    vector<vector<int>> dp(n + 1, vector<int> (tgt+1,-1));
    int res = numTarget(n, k, tgt, dp);
    cout << res;
        
    return 0;
}