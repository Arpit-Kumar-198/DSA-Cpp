/*
    Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
    For example, if n=3, there are 4 ways:

1+1+1
1+2
2+1
3

Input:
The only input line has an integer n.

Output:
Print the number of ways modulo 10^9+7.

Constraints:
1 <= n <= 10^6

Example:

Input:
3

Output:
4

*/

#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;
const int c = 1000000000 + 7;
long long int diceCombination(int n, vector<long long int> &dp, vector<long long int> &pre)
{
    if(n == 0)
        return dp[n] = 1;
    if (n <= 6)
        return dp[n] = pow(2, n - 1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;

    pre[0] = dp[0];
    long long int t = pre[0];
    for (int i = 1; i <= 6; i++)
    {
        pre[i] = dp[i] + t;
        t = pre[i];
    }

    t = pre[6];
    for (int i = 7; i <= n; i++)
    {
        dp[i] = (pre[i - 1] % c - pre[i - 7] % c + c) % c;
        pre[i] = (dp[i] % c + t % c) % c;
        t = pre[i];
    }
    return dp[n]%(c);
}

int main(){

    int n;
    cin >> n;
    vector<long long int> dp(n+1,0);
    vector<long long int> pre(n+1);
    cout << diceCombination(n,dp,pre) << endl;
    return 0;
}
