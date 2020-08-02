int Solution::anytwo(string A) {
    int n = A.size();
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[i] == A[j] && i != j) 
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
    return (dp[n][n] > 1);
}
