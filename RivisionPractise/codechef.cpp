#include <bits/stdc++.h>
#include<string>
using namespace std;
int mod = 1e9+7;
char func(int n, int k, int l, char ch, vector<vector<char>>& dp, int chance)
{
    if (n == 0 && ch == 'A') return 'B';
        
    if (n == 0 && ch == 'B') return 'A';

    if(dp[n][chance] != ' ') return dp[n][chance];
        
    char r1 = ' ', r2 = ' ', r3 = ' ';
    if(n-1 >= 0 ){
        char temp = ch == 'A' ? 'B' : 'A';
        r1 = func(n - 1, k, l, temp, dp, temp == 'A' ? 0 : 1);
    }
    if(n-k >= 0 ){
        char temp = ch == 'A' ? 'B' : 'A';
        r2 = func(n - k, k, l, temp, dp, temp == 'A' ? 0 : 1);
    }
    if(n-l >= 0 ){
        char temp = ch == 'A' ? 'B' : 'A';
        r3 = func(n - l, k, l, temp, dp, temp == 'A' ? 0 : 1);
    }

    if(r1==ch || r2==ch || r3==ch) return dp[n][chance] = ch;
    else return dp[n][chance] = (ch == 'A' ? 'B' : 'A');
}
vector<char> func2(vector<int>& arr, int n, int k, int l){
    vector<char> ans;
    for (int i = 0; i < n; i++)
    {
        vector<vector<char>> dp(arr[i] + 1, vector<char> (2,' '));
        if (func(arr[i], k, l, 'A', dp, 0) == 'A') ans.push_back('A');
        else ans.push_back('B');
    }
    return ans;
}
int main() {
    int k, l, n;
    cin >> k >> l >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
        
    vector<char> ans = func2(arr, n, k, l);
    for(auto ch : ans) cout << ch;
        
    return 0;
}