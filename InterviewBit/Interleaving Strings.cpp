int Solution::isInterleave(string A, string B, string C) {
    int n = A.size(), m = B.size(), l = C.size();
    if (n + m != l) return 0;
    bool dp[n + 1][m + 1];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        dp[i][0] = (A[i - 1] == C[i - 1]) && dp[i - 1][0];
    for (int j = 1; j <= m; j++)
        dp[0][j] = (B[j - 1] == C[j - 1]) && dp[0][j - 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (A[i - 1] == C[i + j - 1] && dp[i - 1][j]) dp[i][j] = 1;
            if (B[j - 1] == C[i + j - 1] && dp[i][j - 1]) dp[i][j] = 1;
        }
    }
    return dp[n][m];
}
