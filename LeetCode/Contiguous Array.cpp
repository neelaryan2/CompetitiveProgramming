class Solution {
   public:
    int findMaxLength(vector<int>& nums) {
        for (int& i : nums)
            if (!i) i = -1;
        map<int, int> mp;
        int sum = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == 0) ans = i + 1;
            if (mp.find(sum) == mp.end())
                mp[sum] = i;
            else
                ans = max(ans, i - mp[sum]);
        }
        return ans;
    }
};