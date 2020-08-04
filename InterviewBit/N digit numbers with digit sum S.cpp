const int mod = 1e9 + 7;
int Solution::solve(int n, int s) {
    int dp[n + 1][s + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= min(s, 9); i++)
        dp[1][i] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= s; j++)
            for (int k = 0; k <= 9; k++)
                if (j >= k)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
    return dp[n][s];
}
