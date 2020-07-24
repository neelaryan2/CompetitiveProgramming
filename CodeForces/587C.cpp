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
const int inf = 1e9;
using pli = pair<ll, int>;
vector<vi> ids;
struct seg_tree {
    vector<int> t;
    int n;
    seg_tree() {}
    int get_element(int i) {
        if (ids[i].empty()) return inf;
        return ids[i].back();
    }
    void build(int m) {
        n = m;
        t.resize(2 * n);
        for (int i = 0; i < n; i++)
            t[i + n] = get_element(i);
        for (int i = n - 1; i > 0; i--)
            t[i] = min(t[i << 1], t[i << 1 | 1]);
    }
    void update(int p) {  // on 0-indexed p
        t[p + n] = get_element(p);
        for (p += n; p >>= 1;)
            t[p] = min(t[p << 1], t[p << 1 | 1]);
    }
    int query(int l, int r) {  // interval [l,r]
        int res = inf;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = min(res, t[l++]);
            if (r & 1) res = min(res, t[--r]);
        }
        return res;
    }
};
seg_tree stree;
int path_query(int a, int b) {
    int res = inf;
    for (; up[a] != up[b]; b = par[up[b]]) {
        if (depth[up[a]] > depth[up[b]]) swap(a, b);
        res = min(res, stree.query(in[up[b]], in[b]));
    }
    if (depth[a] > depth[b]) swap(a, b);
    res = min(res, stree.query(in[a], in[b]));
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    init(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    pre_dfs(0);
    dfs_hld(0);
    ids.resize(n);
    vector<int> inv(m);
    for (int i = 0, c; i < m; i++) {
        cin >> c, c--;
        ids[in[c]].eb(i);
        inv[i] = in[c];
    }
    for (int i = 0; i < n; i++)
        reverse(all(ids[i]));
    stree.build(n);
    while (q--) {
        int v, u, k;
        cin >> v >> u >> k;
        v--, u--;
        vector<int> ans;
        while (k--) {
            int res = path_query(u, v);
            if (res == inf) break;
            ans.eb(res);
            res = inv[res];
            ids[res].pop_back();
            stree.update(res);
        }
        k = ans.size();
        for (int j = k - 1; j >= 0; j--) {
            ids[inv[ans[j]]].eb(ans[j]);
            stree.update(inv[ans[j]]);
            ans[j]++;
        }
        cout << k << ' ';
        for (int i : ans) cout << i << ' ';
        cout << '\n';
    }
}
