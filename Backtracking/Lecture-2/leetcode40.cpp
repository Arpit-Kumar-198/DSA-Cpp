class Solution {
public:
void solve(int idx, int tgt, vector<int>& arr, vector<int>& temp, vector<vector<int>>& ans){
    if(tgt < 0) return;
    if(tgt == 0){
        ans.push_back(temp);
        return;
    }
    for(int i = idx; i < arr.size(); i++){
        if(i > idx && arr[i] == arr[i-1]) continue;
        temp.push_back(arr[i]);
        solve(i+1, tgt-arr[i], arr, temp, ans);
        temp.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        solve(0, target, candidates, temp, ans);
        return ans;
    }
};