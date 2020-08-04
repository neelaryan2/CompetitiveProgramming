int Solution::isMatch(const string A, const string B) {
    int n = A.size(), m = B.size();
    bool dp[n + 1][m + 1];
    memset(dp, 0, sizeof dp);
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char a = A[i - 1], b = B[j - 1];
            if (a == '*') {
                dp[i][j] |= dp[i - 1][j];
                if (i >= 2) {
                    dp[i][j] |= dp[i - 2][j];
                    if (A[i - 2] == '.' || A[i - 2] == b)
                        dp[i][j] |= dp[i][j - 1];
                }
            } else if (b == '*') {
                dp[i][j] |= dp[i][j - 1];
                if (j >= 2) {
                    dp[i][j] |= dp[i][j - 2];
                    if (B[j - 2] == '.' || B[j - 2] == a)
                        dp[i][j] |= dp[i - 1][j];
                }
            } else if (a == '.' || b == '.' || a == b) 
                dp[i][j] |= dp[i - 1][j - 1];
        }
    }
    return dp[n][m];
}
