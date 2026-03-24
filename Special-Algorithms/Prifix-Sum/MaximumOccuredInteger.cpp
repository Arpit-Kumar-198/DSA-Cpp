/*
🔢 Maximum Occurred Integer

You are given two integer arrays L and R (each having N elements), where:
L[i] → start of range
R[i] → end of range
Each pair (L[i], R[i]) represents a range [L[i], R[i]] (inclusive).

🎯 Task

Return the integer that appears in the maximum number of ranges.
👉 If multiple integers have the same maximum frequency, return the smallest one.

📥 Input Format
First line: Integer N
Second line: N space-separated integers (L array)
Third line: N space-separated integers (R array)
5
1 2 3 4 5
4 3 6 7 8

📤 Output Format
Return a single integer:
Integer with maximum occurrences in ranges
3

🔒 Constraints
1 ≤ N ≤ 10^5
0 ≤ L[i], R[i] ≤ 10^5
*/
#include <bits/stdc++.h>
using namespace std;
int func(int N, vector<int>& L, vector<int>& R) {
    int mxEle = INT_MIN;

    for(auto &num : L) mxEle = max(num, mxEle);
    for(auto &num : R) mxEle = max(num, mxEle);

    vector<int> prefix(mxEle + 2, 0);

    for(int i = 0; i < N; i++){
        prefix[L[i]]++;
        prefix[R[i] + 1]--; // inclusive range
    }

    for(int i = 1; i < prefix.size(); i++)
        prefix[i] += prefix[i-1];

    int ans = 0, mxfreq = prefix[0];

    for(int i = 0; i < prefix.size(); i++){
        if(prefix[i] > mxfreq){
            mxfreq = prefix[i];
            ans = i;
        }
        else if(prefix[i] == mxfreq && ans > i){
            ans = i;
        }
    }

    return ans;
}
int main() {
    int N;
    cin >> N;

    vector<int> L(N), R(N);

    for(int i = 0; i < N; i++) cin >> L[i];
    for(int i = 0; i < N; i++) cin >> R[i];

    int maxOccuredInt = func(N, L, R);
    cout << maxOccuredInt << endl;
    return 0;
}