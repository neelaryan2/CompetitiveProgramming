int Solution::solve(vector<int> &a, int k) {
    int n = a.size();
    if (n <= 1) return 0;
    k = min(k, n - 1);
    vector<int> dp(n, 0);
    for (int i = 1; i <= k; i++) {
        int diff = -a[0];
        vector<int> new_dp(n, 0);
        for (int j = 1; j < n; j++) {
            new_dp[j] = max(new_dp[j - 1], a[j] + diff);
            diff = max(diff, dp[j] - a[j]);
        }
        new_dp.swap(dp);
    }
    return dp[n - 1];
}
