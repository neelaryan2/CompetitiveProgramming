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
const ll inf = 1e15;
using pli = pair<ll, int>;
vector<vi> girls;
struct seg_tree_lazy {
    vector<ll> lazy;
    vector<pli> t;
    int n;
    void init(int m) {
        n = m;
        t.assign(4 * n, mp(inf, -1));
        lazy.assign(4 * n, 0);
    }
    pli get_element(int i, int v) {
        if (girls[i].empty()) return mp(inf, -1);
        pli ret = mp(girls[i].back(), i);
        ret.first += lazy[v];
        return ret;
    }
    void apply(int v, ll x) {
        t[v].first += x;
        lazy[v] += x;
    }
    void push(int v) {
        if (!lazy[v]) return;
        apply(v * 2, lazy[v]);
        apply(v * 2 + 1, lazy[v]);
        lazy[v] = 0;
    }
    void pull(int v) {
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
    void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = get_element(tl, v);
            return;
        }
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        pull(v);
    }
    void add(int v, int tl, int tr, int l, int r, ll addend) {
        if (l > r) return;
        if (l == tl && r == tr) return apply(v, addend);
        push(v);
        int tm = (tl + tr) / 2;
        add(v * 2, tl, tm, l, min(r, tm), addend);
        add(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
        pull(v);
    }
    pli get(int v, int tl, int tr, int i) {
        if (tl == tr) return t[v];
        push(v);
        int tm = (tl + tr) / 2;
        if (i <= tm)
            return get(v * 2, tl, tm, i);
        else
            return get(v * 2 + 1, tm + 1, tr, i);
    }
    void update(int v, int tl, int tr, int i) {
        if (tl == tr) {
            t[v] = get_element(tl, v);
            return;
        }
        push(v);
        int tm = (tl + tr) / 2;
        if (i <= tm) update(v * 2, tl, tm, i);
        if (i > tm) update(v * 2 + 1, tm + 1, tr, i);
        pull(v);
    }
    pli query(int v, int tl, int tr, int l, int r) {
        if (l > r) return mp(inf, -1);
        if (l == tl && r == tr) return t[v];
        push(v);
        int tm = (tl + tr) / 2;
        return min(query(v * 2, tl, tm, l, min(r, tm)),
                   query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
    void add(int l, int r, ll x) {
        return add(1, 0, n - 1, l, r, x);
    }
    pli query(int l, int r) {
        pli res = query(1, 0, n - 1, l, r);
        // trace(l, r, res);
        return res;
    }
    void update(int i) {
        return update(1, 0, n - 1, i);
    }
    pli get(int i) {
        return get(1, 0, n - 1, i);
    }
    void build() {
        return build(1, 0, n - 1);
    }
};
seg_tree_lazy stree;
pli path_query(int a, int b) {
    pli res = mp(inf, -1);
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
    stree.init(n);
    girls.resize(n);
    for (int i = 1, c; i <= m; i++) {
        cin >> c, c--;
        girls[in[c]].eb(i);
    }
    for (int i = 0; i < n; i++)
        reverse(all(girls[i]));
    stree.build();
    while (q--) {
        int t, v, u, k;
        cin >> t;
        if (t == 1) {
            cin >> v >> u >> k;
            v--, u--;
            vector<int> ans;
            while (k--) {
                pli res = path_query(u, v);
                if (res.se == -1) break;
                ans.eb(girls[res.se].back());
                girls[res.se].pop_back();
                stree.update(res.se);
            }
            cout << ans.size() << ' ';
            for (int i : ans) cout << i << ' ';
            cout << '\n';
        }
        if (t == 2) {
            cin >> v >> k, v--;
            stree.add(in[v], in[v] + siz[v] - 1, k);
        }
    }
}
