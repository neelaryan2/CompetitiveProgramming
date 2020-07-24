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
int T = 0;
vector<vector<int>> adj;
vector<int> in, up, down, siz, par, depth;
void init(int n) {
    adj.resize(n);
    in.resize(n);
    siz.resize(n);
    up.resize(n);
    par.resize(n);
    down.resize(n);
    depth.resize(n);
}
void pre_dfs(int v = 0, int p = -1, int d = 0) {
    depth[v] = d, siz[v] = 1, par[v] = p;
    up[v] = down[v] = v;
    for (int& u : adj[v]) {
        if (u == p) continue;
        pre_dfs(u, v, d + 1);
        siz[v] += siz[u];
        if (adj[v][0] == p || siz[u] > siz[adj[v][0]])
            swap(u, adj[v][0]);
    }
}
void dfs_hld(int v = 0, int p = -1) {
    in[v] = T++;
    for (int u : adj[v]) {
        if (u == p) continue;
        if (u == adj[v][0]) up[u] = up[v];
        dfs_hld(u, v);
        if (u == adj[v][0]) down[v] = down[u];
    }
}
const int inf = 1e9 + 7;
struct seg_tree {
    vector<int> t;
    int n;
    seg_tree() {}
    int combine(int a, int b) {
        return min(a, b);
    }
    void init(int m) {
        n = m;
        t.assign(2 * n, inf);
    }
    void update(int p, int x) {  // on 0-indexed p
        for (p += n, t[p] = combine(t[p], x); p >>= 1;)
            t[p] = combine(t[p << 1], t[p << 1 | 1]);
    }
    int query(int l, int r) {  // interval [l,r]
        int resl = inf, resr = inf;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resl = combine(resl, t[l++]);
            if (r & 1) resr = combine(t[--r], resr);
        }
        return combine(resl, resr);
    }
};
seg_tree upv, downv;
void red(int v) {
    int d = 0, p;
    while (true) {
        upv.update(in[v], depth[down[v]] - depth[v] + d);
        downv.update(in[v], depth[v] - depth[up[v]] + d);
        p = par[up[v]];
        if (p == -1) break;
        d += depth[v] - depth[p];
        v = p;
    }
}
int nearest(int v) {
    int ret = inf, d = 0, p;
    while (true) {
        int q = upv.query(in[up[v]], in[v]);
        q -= depth[down[v]] - depth[v];
        int w = downv.query(in[v], in[down[v]]);
        w -= depth[v] - depth[up[v]];
        ret = min(ret, d + min(q, w));
        p = par[up[v]];
        if (p == -1) break;
        d += depth[v] - depth[p];
        v = p;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    init(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    pre_dfs();
    dfs_hld();
    upv.init(n);
    downv.init(n);
    red(0);
    trace(up);
    trace(down);
    trace(in);
    for (int _ = 0; _ < m; _++) {
        int t, v;
        cin >> t >> v;
        t--, v--;
        if (t == 0) {
            red(v);
        }
        if (t == 1) {
            cout << nearest(v) << '\n';
        }
    }
}
