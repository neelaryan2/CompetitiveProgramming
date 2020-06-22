/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> g(n, vi(m, 0));
    vector<vi> vis(n, vi(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    int ans = 0;
    vector<pii> vec(m + n - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j]) vec[i + j].fi++;
            if (!g[i][j]) vec[i + j].se++;
        }
    }
    ld l = ((ld)m + n - 2) / 2;
    for (int i = 0; i < l; i++) {
        pii p1 = vec[i];
        pii p2 = vec[m + n - 2 - i];
        ans += min(p1.fi + p2.fi, p1.se + p2.se);
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
