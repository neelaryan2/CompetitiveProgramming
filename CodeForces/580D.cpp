#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < k; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        adj[x][y] = c;
    }
    ll ans = 0;
    vector<vector<ll>> dp(1 << n, vector<ll>(n, 0));
    for (int i = 1; i < (1 << n); i++) {
        vector<int> vec;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) continue;
            vec.push_back(j);
        }
        for (int t = 0; t < n; t++) {
            for (int j : vec) {
                int ni = i + (i << j);
                dp[ni][j] = max(dp[ni][j], dp[i][t] + adj[t][j] + a[j]);
            }
        }
        if (vec.size() == n - m) {
            for (int j = 0; j < n; j++)
                ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}