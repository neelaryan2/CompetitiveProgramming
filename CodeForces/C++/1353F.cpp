/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const ll inf = 1e18;
const ll N = 1e2 + 5;
// min sum DP
ll a[N][N], dp[N][N];
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            a[i][j] -= i + j;
            cerr << a[i][j] << " ";
        }
        cerr << endl;
    }
    ll ans = inf;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ll ref = a[i][j];
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    if (a[x][y] >= ref)
                        dp[x][y] = a[x][y];
                    else
                        dp[x][y] = inf;
                }
            }
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    if (dp[x][y] == inf) continue;
                    ll res = inf + 5;
                    if (x) res = min(res, dp[x - 1][y]);
                    if (y) res = min(res, dp[x][y - 1]);
                    if (res == inf)
                        dp[x][y] = inf;
                    else if (res == inf + 5)
                        continue;
                    else
                        dp[x][y] += res;
                }
            }
            ll cost = dp[n - 1][m - 1];
            if (cost >= inf) continue;
            cost -= ref * (n + m - 1);
            ans = min(ans, cost);
        }
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
