class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums) total += x;

        int tgt = total % p;
        if (tgt == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;  // important

        long long prefix = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            prefix = (prefix + nums[i]) % p;

            int need = (prefix - tgt + p) % p;
            if (mp.find(need) != mp.end()) ans = min(ans, i - mp[need]);
            mp[prefix] = i;
        }
        return ans == nums.size() ? -1 : ans;
    }
};