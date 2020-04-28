#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<ll>;
#define mp make_pair
#define fi first
#define se second
#define popcnt __builtin_popcount
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    vector<vi> adj(n, vi(n, 0));
    for (int i = 0; i < k; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--, y--;
        adj[x][y] = c;
    }
    vector<int> vec(1 << n, 0);
    iota(all(vec), 0);
    sort(all(vec), [](int& a, int& b) {
        return popcnt(a) < popcnt(b);
    });
    vector<vi> dp(1 << n, vi(n, 0));
    for (int i : vec) {
        for (int b = 0; b < n; b++) {
            if ((i >> b) & 1) {
                int ni = i ^ (1 << b);
                if (ni == 0) {
                    dp[i][b] = a[b];
                    continue;
                }
                for (int j = 0; j < n; j++) {
                    if ((ni >> j) & 1) {
                        dp[i][b] = max(dp[i][b], dp[ni][j] + adj[j][b] + a[b]);
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i < (1 << n); i++) {
        ll cnt = 0, curr = 0;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) cnt++;
            curr = max(curr, dp[i][j]);
        }
        if (cnt == m) ans = max(ans, curr);
    }
    cout << ans << '\n';
}

