class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2));
        dp[0][0] = dp[0][1] = 0;
        for (int i = 0; i < n; i++) {
            dp[i + 1][0] = dp[i][1];
            dp[i + 1][1] = max(dp[i][0] + nums[i], dp[i][1]);
        }
        return max(dp[n][0], dp[n][1]);
    }
};