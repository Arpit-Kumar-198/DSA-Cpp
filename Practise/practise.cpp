#include<bits/stdc++.h>
using namespace std;

void solve(int idx, vector<int>& arr, vector<vector<int>>& ans){
    if(idx == arr.size()){
        ans.push_back(arr);
        return;
    }
    unordered_set<int> seen;
    for (int i = idx; i < arr.size(); i++)
    {
        if(seen.count(arr[i])) continue;
        
        swap(arr[i], arr[idx]);
        seen.insert(arr[i]);
        solve(idx + 1, arr, ans);
        swap(arr[i], arr[idx]);
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;
    vector<vector<int>> ans;
    solve(0, arr, ans);
    for(auto vec : ans){
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
    }
    return 0;
}