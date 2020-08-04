using ll = long long;
int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    if (n == 0) return 0;
    int m = A[0].size();
    vector<vector<ll>> p(n + 1, vector<ll>(m + 1, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            p[i + 1][j + 1] = p[i][j + 1] + A[i][j];
    int ans = 0;
    for (int l = 0; l <= n; l++) {
        for (int r = l + 1; r <= n; r++) {
            map<ll, int> cnt; ll cur = 0;
            for (int i = 0; i <= m; i++) {
                cur += p[r][i] - p[l][i];
                ans += cnt[cur]++;
            }
        }
    }
    return ans;
}
