class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        vector<int> ans(2);
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(target - nums[i]) != mp.end()) {
                ans[0] = mp[target - nums[i]];
                ans[1] = i;
                return ans;
            }
            mp[nums[i]] = i;
        }
        assert(false);
        return ans;
    }
};