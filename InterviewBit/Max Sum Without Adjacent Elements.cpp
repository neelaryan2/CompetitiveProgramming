int Solution::adjacent(vector<vector<int> > &A) {
    int n = A[0].size(), ans = 0;
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i ++) {
        int a = max(A[0][i], A[1][i]);
        dp[i] = a;
        if (i >= 2) dp[i] = max(dp[i], a + dp[i - 2]);
        if (i >= 3) dp[i] = max(dp[i], a + dp[i - 3]);
        ans = max(ans, dp[i]);
    }
    return ans;
}
