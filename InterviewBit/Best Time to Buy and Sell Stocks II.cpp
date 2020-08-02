int Solution::maxProfit(const vector<int> &A) {
    int n = A.size(), ans = 0;
    for (int i = 1; i < n; i++)
        ans += max(A[i] - A[i - 1], 0);
    return ans;
}
