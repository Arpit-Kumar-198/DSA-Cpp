#include<bits/stdc++.h>
using namespace std;
/*
    Revision Topics :

    Heaps
    Trees
    Stack and Queue
    Searching

*/
void solve(int idx, vector<int>& arr, vector<int>& temp, vector<vector < int >>& ans, int k){
    if(temp.size() == k) ans.push_back(temp);
    for (int i = idx; i < arr.size(); i++){
        if(i > idx && arr[i] == arr[i-1]) continue;
        temp.push_back(arr[i]);
        solve(i + 1, arr, temp, ans, k);
        temp.pop_back();
    }
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> temp;
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    solve(0, arr, temp, ans, k);
    cout << "Subsets : " << endl;
    for (auto vec : ans)
    {
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
    }
    return 0;
}