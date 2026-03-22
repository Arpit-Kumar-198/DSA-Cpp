#include<bits/stdc++.h>
using namespace std;
int maxSumGoodSubarray(vector<int>& arr, int n, int k){
    int i = 0, j = 0, sum = 0, ans = 0;
    unordered_map<int, int> mp;
    while (j < n)
    {
        if(arr[j] >= 0) {
            mp[arr[j]]++;
            sum += arr[j];
        }

        while(i < n && mp.size() > k){
            if(arr[i] >= 0){
                mp[arr[i]]--;
                if(mp[arr[i]] == 0) mp.erase(arr[i]);
                sum -= arr[i];
            }
            i++;
        }
        ans = max(ans, sum);
        j++;
    }
    return ans;
}
int main(){
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> k;
    cout << maxSumGoodSubarray(arr, n, k);
    return 0;
}