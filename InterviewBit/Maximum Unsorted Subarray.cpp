vector<int> Solution::subUnsort(vector<int> &A) {
    int n = A.size();
    int l = -1, r = -1;
    for (int i = 1; i < n; i++)
        if (A[i] < A[i - 1]) {
            l = i - 1;
            break;
        }
    if (l == -1) return {-1};
    for (int i = n - 2; i >= 0; i--)
        if (A[i] > A[i + 1]) {
            r = i + 1;
            break;
        }
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = l; i <= r; i++) {
        mn = min(mn, A[i]);
        mx = max(mx, A[i]);
    }
    for (int i = 0; i <= l; i++)
        if (A[i] > mn) {
            l = i;
            break;
        }
    for (int i = n - 1; i >= r; i--)
        if (A[i] < mx) {
            r = i;
            break;
        }
    return {l, r};
}
