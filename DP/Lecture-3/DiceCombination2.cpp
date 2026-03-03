#include <bits/stdc++.h>
#include<string>
using namespace std;
int mod = 1e9+7;
int diceCombination(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++){
        int a1 = i - 1, a2 = i - 2, a3 = i - 3, a4 = i - 4, a5 = i - 5, a6 = i - 6;
        if(a1 >= 0) dp[i] = (dp[i]%mod + dp[a1]%mod)%mod;
        if(a2 >= 0) dp[i] = (dp[i]%mod + dp[a2]%mod)%mod;
        if(a3 >= 0) dp[i] = (dp[i]%mod + dp[a3]%mod)%mod;
        if(a4 >= 0) dp[i] = (dp[i]%mod + dp[a4]%mod)%mod;
        if(a5 >= 0) dp[i] = (dp[i]%mod + dp[a5]%mod)%mod;
        if(a6 >= 0) dp[i] = (dp[i]%mod + dp[a6]%mod)%mod;
    }
    return dp[n];
}
int main() {
    int n;
    cin >> n;
    int res = diceCombination(n);
    cout << res;
        
    return 0;
}