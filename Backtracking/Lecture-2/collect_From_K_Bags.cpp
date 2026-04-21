/* Collect from K Bags

You are given N non-empty bags, each containing M distinct non-negative integers. All integers are unique across all bags.

Your task is to find all possible combinations formed by selecting numbers from exactly K different bags, such that:

1. You pick exactly one number from each selected bag.
2. The sum of the selected numbers is equal to S.

Return all such valid combinations, in any order. If no such combinations are found, return an empty list.

Input Format:
The first line contains four space-separated integers: N, M, K, and S. Each of the next N lines contains M space-separated integers, where the i-th line represents the contents of the i-th bag.

Output Format:
Each valid combination will be printed on a new line. Within each combination, the selected integers will be separated by a single space.

Constraints:
1 <= K <= N <= 12
1 <= M <= 5
1 <= S <= 1000
1 <= Numbers in Bags <= 1000

Sample Input:
4 3 3 18
1 2 3
4 5 6
7 8 9
10 11 12

Sample Output: 
1 5 12
1 6 11
1 7 10
2 4 12
2 5 11
2 6 10
3 4 11
3 5 10
3 6 9

Explanation:
There are 4 (=N) bags, each having 3 (= M ) numbers, and we are expected to pick exactly 3 numbers from 3 different bags (= K ) The sum of the picked numbers is expected to be 18 (= S )

Under the given conditions there are only 9 unique combinations possible, as given above.
It can be verified that exactly 3 numbers are picked from 3 different bags. For example, the numbers in the fifth combination (2, 5, and 11) are picked from 1st, 2nd and 4th bags respectively.
It can also be verified that the sum of each combination is exactly 18.

*/

#include<bits/stdc++.h>
using namespace std;
void solve(int bagidx, int chosen, int sum, int k, int s, vector<vector<int>>& bags, vector<int>& temp, vector<vector<int>>& ans){
    if(sum > s) return;
    if(chosen == k && sum == s) {
        ans.push_back(temp);
        return;
    }
    if(bagidx == bags.size()) return;

    // dont choose the bag
    solve(bagidx+1, chosen, sum, k, s, bags, temp, ans);

    // choose the bag
    for(int i = 0; i < bags[bagidx].size(); i++){
        temp.push_back(bags[bagidx][i]);
        solve(bagidx+1, chosen+1, sum+bags[bagidx][i], k, s, bags, temp, ans);
        temp.pop_back();
    }
}
int main(){
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vector<vector<int>> bags(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int x;
            cin >> x;
            bags[i][j] = x;
        }
    }
    // sorting required so that we could stop the recursion when sum > s
    for(auto &vec : bags) sort(vec.begin(), vec.end());
    sort(bags.begin(), bags.end());

    vector<int> temp;
    vector<vector<int>> ans;

    solve(0, 0, 0, k, s, bags, temp, ans);

    for(auto &vec : ans){
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
    }
    return 0;
}