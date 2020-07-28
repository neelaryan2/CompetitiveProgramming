int Solution::maxSubArray(const vector<int> &A) {
    int n = A.size();
    int ans = INT_MIN, mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, 0) + A[i];
        ans = max(ans, mx);
    }
    return ans;
}
