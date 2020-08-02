int Solution::longestValidParentheses(string A) {
    int n = A.size(), ans = 0;
    vector<int> dp(n, 0);
    for (int i = 1; i < n; i++) {
        if (A[i] == '(') continue;
        if (A[i - 1] == '(') dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
        else {
            int j = (i - 1) - dp[i - 1];
            if (j >= 0 && A[j] == '(') 
                dp[i] = dp[i - 1] + 2 + (j >= 1 ? dp[j - 1] : 0);
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
