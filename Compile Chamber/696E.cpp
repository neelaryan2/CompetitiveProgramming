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
struct seg_tree_lazy {
    vector<int> t, a, lazy;
    int n;
    void init(int m) {
        n = m;
        a.assign(n, inf);
        t.assign(4 * n, inf);
        lazy.assign(4 * n, 0);
    }
    void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        pull(v);
    }
    void push(int v) {
        if (!lazy[v]) return;
        int l = v * 2, r = l + 1;
        lazy[l] += lazy[v];
        lazy[r] += lazy[v];
        if (t[l] != inf) t[l] += lazy[v];
        if (t[r] != inf) t[r] += lazy[v];
        lazy[v] = 0;
    }
    void pull(int v) {
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
    void add_aux(int v, int tl, int tr, int l, int r, int addend) {
        if (l > r || t[v] == inf) return;
        if (l == tl && tr == r) {
            t[v] += addend;
            lazy[v] += addend;
        } else {
            int tm = (tl + tr) / 2;
            push(v);
            add_aux(v * 2, tl, tm, l, min(r, tm), addend);
            add_aux(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
            pull(v);
        }
    }
    int get_aux(int v, int tl, int tr, int i) {
        if (tl == tr) return t[v];
        push(v);
        int tm = (tl + tr) / 2;
        int ret;
        if (i <= tm) ret = get_aux(v * 2, tl, tm, i);
        if (i > tm) ret = get_aux(v * 2 + 1, tm + 1, tr, i);
        pull(v);
        return ret;
    }
    void update_aux(int v, int tl, int tr, int i, int x) {
        if (tl == tr) {
            a[tl] = t[v] = x;
            if (x != inf) t[v] += lazy[v];
            return;
        }
        push(v);
        int tm = (tl + tr) / 2;
        if (i <= tm) update_aux(v * 2, tl, tm, i, x);
        if (i > tm) update_aux(v * 2 + 1, tm + 1, tr, i, x);
        pull(v);
    }
    int query_aux(int v, int tl, int tr, int l, int r) {
        if (l > r || t[v] == inf) return -1;
        if (tl == tr) return tl;
        int tm = (tl + tr) / 2;
        push(v);
        if (t[v * 2] == t[v])
            return query_aux(v * 2, tl, tm, l, min(r, tm));
        else
            return query_aux(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        pull(v);
    }
    void add(int l, int r, int x) {
        return add_aux(1, 0, n - 1, l, r, x);
    }
    int query(int l, int r) {
        int res = query_aux(1, 0, n - 1, l, r);
        trace(l, r, res);
        return res;
    }
    void update(int i, int x) {
        return update_aux(1, 0, n - 1, i, x);
    }
    int get(int i) {
        return get_aux(1, 0, n - 1, i);
    }
    void build() {
        return build(1, 0, n - 1);
    }
};
seg_tree_lazy stree;
int path_query(int a, int b) {
    int res = -1;
    for (; up[a] != up[b]; b = par[up[b]]) {
        if (depth[up[a]] > depth[up[b]]) swap(a, b);
        int id = stree.query(in[up[b]], in[b]);
        if (id == -1) continue;
        if (res == -1 || stree.get(id) < stree.get(res)) res = id;
    }
    if (depth[a] > depth[b]) swap(a, b);
    int id = stree.query(in[a], in[b]);
    if (id == -1) return res;
    if (res == -1 || stree.get(id) < stree.get(res)) res = id;
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
    vector<vi> girls(n);
    for (int i = 1, c; i <= m; i++) {
        cin >> c, c--;
        girls[in[c]].eb(i);
    }
    for (int i = 0; i < n; i++) {
        if (girls[i].empty()) continue;
        reverse(all(girls[i]));
        stree.a[i] = girls[i].back();
    }
    stree.build();
    trace(in);
    while (q--) {
        int t, v, u, k, val;
        cin >> t;
        if (t == 1) {
            cin >> v >> u >> k;
            v--, u--;
            vector<int> ans;
            while (k--) {
                int res = path_query(u, v);
                trace(q, res);
                if (res == -1) break;
                int it = girls[res].back();
                ans.eb(it);
                girls[res].pop_back();
                int old = stree.get(res);
                if (girls[res].empty())
                    stree.add(res, res, inf - old);
                else
                    stree.add(res, res, girls[res].back() - old);
            }
            cout << ans.size() << ' ';
            for (int i : ans) cout << i << ' ';
            cout << '\n';
        }
        if (t == 2) {
            cin >> v >> k;
            v--;
            stree.add(in[v], in[v] + siz[v] - 1, k);
        }
    }
}
