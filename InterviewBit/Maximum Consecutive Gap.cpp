using ld = long double;
int Solution::maximumGap(const vector<int> &a) {
    int mn = INT_MAX, mx = INT_MIN;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    ld sz = ((ld)mx - mn) / (n - 1);
    if (n < 2 || mx == mn) return 0;
    vector<int> mnb(n, INT_MAX), mxb(n, INT_MIN);
    for (int i = 0; i < n; i++) {
        int j = ((ld)a[i] - mn) / sz;
        mxb[j] = max(mxb[j], a[i]);
        mnb[j] = min(mnb[j], a[i]);
    }
    int ans = 0, prv = mxb[0];
    for (int i = 1; i < n; i++) {
        if (mnb[i] == INT_MAX) continue;
        int gap = mnb[i] - prv;
        prv = mxb[i];
        ans = max(ans, gap);
    }
    return ans;
}
