int Solution::numDistinct(string A, string B) {
    int n = A.size(), m = B.size();
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (A[i] == B[j]) dp[i + 1][j + 1] += dp[i][j];
            dp[i + 1][j + 1] += dp[i][j + 1];
        }
    }
    return dp[n][m];
}
