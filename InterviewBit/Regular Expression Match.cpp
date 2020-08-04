int Solution::isMatch(const string A, const string B) {
    int n = A.size(), m = B.size();
    bool dp[n + 1][m + 1];
    memset(dp, 0, sizeof dp);
    dp[0][0] = true;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            char a = A[i - 1], b = B[j - 1];
            if (i && a == '*') {
                dp[i][j] |= dp[i - 1][j];
                if (j) dp[i][j] |= dp[i][j - 1];
            } else if (j && b == '*') {
                dp[i][j] |= dp[i][j - 1];
                if (i) dp[i][j] |= dp[i - 1][j];
            } else if (i == 0 || j == 0) {
                dp[i][j] = (i == 0) && (j == 0);
            } else if (a == '?' || b == '?' || a == b) 
                dp[i][j] |= dp[i - 1][j - 1];
        }
    }
    return dp[n][m];
}
