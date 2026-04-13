class Solution {
public:
void helper(int idx, vector<int>& nums, vector<int> temp, vector< vector<int> >& res)
{
    res.push_back(temp);
    for(int i = idx; i < nums.size(); i++){
        if(i > idx && nums[i] == nums[i-1]) continue;
        temp.push_back(nums[i]);
        helper(i+1, nums, temp, res);
        temp.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       vector<int> temp;
       vector< vector<int> > res;
       helper(0, nums, temp, res);
       return res;
    }
};