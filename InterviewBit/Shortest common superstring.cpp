using vi = vector<int>;
int Solution::solve(vector<string> &A) {
    int n = A.size();
    vector<vi> overlap(n, vi(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int l1 = A[i].size(), l2 = A[j].size();
            for (int l = 0; l < l1; l++) {
                if (l1 - l > l2) continue;
                if (A[i].substr(l, l1 - l) == A[j].substr(0, l1 - l)) {
                    overlap[i][j] = l1 - l;
                    break;
                }
            }
        }
    }
    int e = (1 << n);
    vector<vi> dp(e, vi(n, 0));
    for (int mask = 1; mask < (1 << n); mask++)
        for (int i = 0; i < n; i++)
            if ((mask >> i) & 1) {
                int submask = mask ^ (1 << i);
                if (submask == 0) continue;
                for (int j = 0; j < n; j++)
                    if ((submask >> j) & 1)
                        dp[mask][i] = max(dp[mask][i], dp[submask][j] + overlap[j][i]);
            }
    int mx = -1, tot = 0;
    for (int i = 0; i < n; i++) {
        tot += A[i].size();
        mx = max(mx, dp[e - 1][i]);
    }
    return tot - mx;
}
