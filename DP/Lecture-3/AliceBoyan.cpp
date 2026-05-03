#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(){
    /*
        Asen and Boyan playing a game , they have n coins , one can pick either 1 , k or l coins from the n coins , the winner will be the one who will pick last coin. If Asen starts the game who will be the winner ?

        Input : k, l, m where m is an array of number of coins .
                n1, n2, n3, ... nm
        example : 2 3 5
                  3 12 113 25714 88888

        1 < k < l < 10
        3 < m < 50
        1 <= Ni <= 1000000
    */

    int k, l, m;
    cin >> k >> l >> m;
    int n[m];
    for (int i = 0; i < m; i++) cin >> n[i];


    vector<int> dp(1000000+1,0);

    for (int i = 1; i < dp.size(); i++) {

        bool win = false;

        if (i - 1 >= 0 && dp[i - 1] == 0)
            win = true;

        if (i - k >= 0 && dp[i - k] == 0)
            win = true;

        if (i - l >= 0 && dp[i - l] == 0)
            win = true;

        dp[i] = win;
    }

    for (int i = 0; i < m; i++){
        if(dp[n[i]] == 1) cout << 'A';
        else cout << 'B';
    }

    return 0;
}