#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
long long query2(vector<int> &arr, int l, int r)
{
    if(l < 0 || r >= arr.size()) return 0;
    long long sum = 0;
    for (int i = l; i <= r; i++) sum += arr[i];
    return sum;
}
void query1(vector<int>& arr, int l, int r){
    if(l < 0 || r >= arr.size()) return;
    for (int i = l; i <= r; i++) arr[i] = arr[l] * (i - l + 1);
    return;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int q;
    cin >> q;
    vector<vector<int>> query(q, vector<int>(3));
    for (int i = 0; i < q; i++)
        cin >> query[i][0] >> query[i][1] >> query[i][2];

    long long ans = 0;
    for (int i = 0; i < q; i++)
    {
        if(query[i][0] == 1) query1(arr, query[i][1], query[i][2]);
        else {
            long long sum = query2(arr, query[i][1], query[i][2]);
            ans = (ans%MOD + sum%MOD)%MOD;
        }
    }
    cout << ans;
    return 0;
}