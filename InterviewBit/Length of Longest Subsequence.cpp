int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n = A.size();
    int dp[2][n];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < n; i++) {
        dp[0][i] = 1;
        for (int j = 0; j < i; j++)
            if (A[j] < A[i])
                dp[0][i] = max(dp[0][i], dp[0][j] + 1);
    }
    for (int i = n - 1; i >= 0; i--) {
        dp[1][i] = 1;
        for (int j = i + 1; j < n; j++) 
            if (A[j] < A[i])
                dp[1][i] = max(dp[1][i], dp[1][j] + 1);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) 
        ans = max(ans, dp[0][i] + dp[1][i] - 1);
    return ans;
}
