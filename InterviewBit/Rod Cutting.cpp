using ll = long long;
using vl = vector<ll>;
using vi = vector<int>;
const ll inf = 1e18 + 7;
vi Solution::rodCut(int n, vi &a) {
    a.insert(a.begin(), 0);
    a.push_back(n);
    int m = a.size();
    vector<vl> dp(m, vl(m, inf));
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < m; j++)
            if (j - i < 2) dp[i][j] = 0;
    for (int l = 3; l <= m; l++)
        for (int i = 0, j = l - 1; j < m; i++, j++)
            for (int k = i + 1; k < j; k++)
                dp[i][j] = min(dp[i][j], a[j] - a[i] + dp[i][k] + dp[k][j]);
    function<vi(int, int)> build = [&](int l, int r) {
        if (r - l < 2) return vi();
        for (int i = l + 1; i < r; i++) {
            if (dp[l][r] == a[r] - a[l] + dp[l][i] + dp[i][r]) {
                vi v1 = build(l, i);
                vi v2 = build(i, r);
                if (v1 > v2) swap(v1, v2);
                vi v(1, a[i]);
                for (int c : v1) v.push_back(c);
                for (int c : v2) v.push_back(c);
                return v;
            }
        }
    };
    return build(0, m - 1);
}
