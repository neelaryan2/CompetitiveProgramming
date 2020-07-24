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
vector<vi> adj;
vector<int> tops, vis;
bool bad;
void dfs(int v) {
    trace(v);
    vis[v] = 1;
    for (int u : adj[v]) {
        if (vis[u] == 1) {
            bad = true;
            return;
        }
        if (vis[u] != 2) dfs(u);
    }
    vis[v] = 2;
    tops.eb(v);
}
void solve(int test) {
    int n, m;
    cin >> n >> m;
    vis.clear();
    vis.assign(n, 0);
    adj.clear();
    bad = false;
    adj.assign(n, {});
    tops.clear();
    vector<pii> edges, dir;
    trace(adj);
    for (int i = 0; i < m; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        u--, v--;
        if (t == 0) {
            if (u > v) swap(u, v);
            edges.pb(mp(u, v));
            continue;
        }
        dir.eb(u, v);
        adj[u].eb(v);
    }
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        dfs(i);
        if (bad) {
            cout << "NO\n";
            return;
        }
    }
    reverse(all(tops));
    vector<int> inv(n);
    for (int i = 0; i < n; i++)
        inv[tops[i]] = i;
    cout << "YES\n";
    trace(tops);
    for (pii& p : edges) {
        int ix = inv[p.fi], iy = inv[p.se];
        if (ix > iy) swap(p.fi, p.se);
        cout << p.fi + 1 << ' ' << p.se + 1 << '\n';
    }
    for (pii& p : dir) {
        cout << p.fi + 1 << ' ' << p.se + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
