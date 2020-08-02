int lcs(const string& A, const string& B) {
    int n = A.size(), m = B.size();
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (A[i] == B[j]) 
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
    return dp[n][m];
}
int Solution::solve(string A) {
    string B = A;
    reverse(B.begin(), B.end());
    return lcs(A, B);
}
