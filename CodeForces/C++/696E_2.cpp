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
    vector<pli> t;
    vector<ll> d;
    int n, h;
    seg_tree_lazy() {}
    void init(int m = 0) {
        n = m;
        h = 32 - __builtin_clz(n);
        d.assign(2 * n, 0);
        t.assign(2 * n, mp(inf, -1));
    }
    pli get_element(int i) {
        if (girls[i].empty()) return mp(inf, -1);
        pli ret = mp(girls[i].back(), i);
        ret.first += d[i + n];
        return ret;
    }
    void build() {
        for (int i = 0; i < n; i++)
            t[i + n] = get_element(i);
        for (int i = n - 1; i > 0; i--)
            t[i] = min(t[i << 1], t[i << 1 | 1]);
    }
    void apply(int p, ll value) {
        d[p] += value;
        t[p].first += value;
    }
    void push_up(int p) {
        for (int c = 2; p >>= 1; c <<= 1) {
            pli lef = t[p << 1], righ = t[p << 1 | 1];
            lef.first += d[p], righ.first += d[p];
            t[p] = min(lef, righ);
        }
    }
    void push_down(int p) {
        for (int s = h; s > 0; --s) {
            int i = p >> s;
            if (d[i] != 0) {
                apply(i << 1, d[i]);
                apply(i << 1 | 1, d[i]);
                d[i] = 0;
            }
        }
    }
    void add(int l, int r, ll value) {
        if (r < l || r >= n || l < 0) return;
        l += n, r += n + 1;
        int _l = l, _r = r;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) apply(l++, value);
            if (r & 1) apply(--r, value);
        }
        push_up(_l), push_up(_r - 1);
    }
    void update(int p) {  // on 0-indexed p
        push_down(p + n);
        t[p + n] = get_element(p);
        push_up(p + n);
    }
    pli query(int l, int r) {
        pli res = mp(inf, -1);
        if (r < l || r >= n || l < 0) return res;
        l += n, r += n + 1;
        push_down(l), push_down(r - 1);
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = min(res, t[l++]);
            if (r & 1) res = min(res, t[--r]);
        }
        return res;
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
    trace(girls);
    stree.build();
    // for (int i = 0; i < n; i++)
    //     trace(i, stree.query(i, i));
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
