int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    vector<int> p(n + 1, 0);
    for (int i = 0; i < n; i++)
        p[i + 1] = p[i] + A[i];
    int ans = INT_MIN;
    for (int i = 0; i <= B; i++)
        ans = max(ans, p[i] + p[n] - p[n - B + i]);
    return ans;
}
