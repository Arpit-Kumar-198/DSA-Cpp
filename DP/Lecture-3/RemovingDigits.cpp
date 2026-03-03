/* You are given an integer n. On each step, you may subtract one of the digits from the number.
How many steps are required to make the number equal to 0?
Input
The only input line has an integer n.
Output
Print one integer: the minimum number of steps.
Constraints

1 <= n <= 10^6

Example
Input:
27

Output:
5

Explanation: An optimal solution is 27 \rightarrow 20 \rightarrow 18 \rightarrow 10 \rightarrow 9 \rightarrow 0.

*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> get_digit(int n){
    vector<int> res;
    while (n > 0)
    {
        if(n % 10 != 0){
            res.push_back(n % 10);
        }
        n /= 10;
    }
    return res;
}
int func(int n, vector<int>& dp){
    if(n == 0)
        return 0;
    if(n <= 9)
        return dp[n] = 1;

    if(dp[n] != -1)
        return dp[n];

    vector<int> d = get_digit(n);

    int result = INT_MAX;
    for (int i = 0; i < d.size(); i++)
    {
        result = min(result, func(n - d[i],dp));
    }
    return dp[n] = 1 + result;
}

int func2(int n, vector<int>& dp){
    if(n == 0)
        return 0;
    if(n <= 9)
        return 1;

    dp[0] = 0;
    for (int i = 1; i <= 9; i++)
        dp[i] = 1;

    
    for (int x = 10; x <= n; x++){

        int result = INT_MAX;
        vector<int> d = get_digit(x);

        for (int i = 0; i < d.size(); i++)
        {
            result = min(result, dp[x - d[i]]);
        }

        dp[x] = 1 + result;
    }
    return dp[n];
}
int main(){

    int n;
    cin >> n;
    vector<int> dp(n+1,-1);
    cout << func2(n, dp) << endl;
    return 0;
}
