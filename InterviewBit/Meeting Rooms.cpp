int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        l[i] = A[i][0];
        r[i] = A[i][1];
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int j = upper_bound(r.begin(), r.end(), l[i]) - r.begin();
        ans = max(ans, i - j + 1);
    }
    return ans;
}
