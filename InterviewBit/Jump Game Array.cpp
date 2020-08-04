int Solution::canJump(vector<int> &A) {
    int n = A.size();
    vector<int> dp(n, -1);
    dp[0] = 0;
    for (int i = 0, j = 1; i < n; i++)
        if (dp[i] != -1)
            while (j < n && j <= i + A[i])
                dp[j++] = dp[i] + 1;
    return (dp[n - 1] != -1);
}
