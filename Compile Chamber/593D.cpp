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
struct Edge {
    int u, v, h;
    ll x;
    Edge(int uu, int vv, ll xx) {
        u = uu, v = vv, x = xx, h = -1;
    }
    int get(int t) { return t ^ u ^ v; }
};
vector<Edge> edges;
int T = 0;
vector<vector<int>> adj;
vector<ll> val;
vector<int> in, up, down, siz, par, depth;
void init(int n) {
    adj.resize(n);
    in.resize(n);
    siz.resize(n);
    up.resize(n);
    par.resize(n);
    down.resize(n);
    depth.resize(n);
    val.resize(n);
}
void pre_dfs(int v = 0, int p = -1, int d = 0) {
    depth[v] = d, siz[v] = 1, par[v] = p;
    up[v] = down[v] = v;
    for (int& i : adj[v]) {
        int u = edges[i].get(v);
        int r = edges[adj[v][0]].get(v);
        if (u == p) continue;
        edges[i].h = u;
        pre_dfs(u, v, d + 1);
        siz[v] += siz[u];
        if (r == p || siz[u] > siz[r])
            swap(i, adj[v][0]);
    }
}
void dfs_hld(int v = 0, int p = -1) {
    in[v] = T++;
    for (int i : adj[v]) {
        int u = edges[i].get(v);
        int r = edges[adj[v][0]].get(v);
        if (u == p) continue;
        if (u == r) up[u] = up[v];
        dfs_hld(u, v);
        val[in[u]] = edges[i].x;
        if (u == r) down[v] = down[u];
    }
}
struct node {
    ll val;
    node(ll v = 1) {
        val = v;
    }
    node operator+(const node& oth) {
        if (val == -1) return *this;
        if (oth.val == -1) return oth;
        ld l = val, r = oth.val;
        if (l > LLONG_MAX / r) return node(-1);
        return node(val * oth.val);
    }
};
template <class node>
struct seg_tree {
    vector<node> t;
    int n;
    seg_tree() {}
    void build(vector<ll>& a) {
        n = a.size();
        t.resize(2 * n);
        for (int i = 0; i < n; i++)
            t[i + n] = node(a[i]);
        for (int i = n - 1; i > 0; i--)
            t[i] = t[i << 1] + t[i << 1 | 1];
    }
    void update(int p, ll x) {  // on 0-indexed p
        for (t[p += n] = node(x); p >>= 1;)
            t[p] = t[p << 1] + t[p << 1 | 1];
    }
    node query(int l, int r) {  // interval [l,r]
        node resl, resr;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resl = resl + t[l++];
            if (r & 1) resr = t[--r] + resr;
        }
        return resl + resr;
    }
};
seg_tree<node> stree;
node path_query(int a, int b) {
    node res;
    for (; up[a] != up[b]; b = par[up[b]]) {
        if (depth[up[a]] > depth[up[b]]) swap(a, b);
        // (in[up[b]], in[b]) is the segment
        res = res + stree.query(in[up[b]], in[b]);
    }
    if (depth[a] > depth[b]) swap(a, b);
    // (in[a], in[b]) is the segment
    res = res + stree.query(in[a] + 1, in[b]);
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    init(n);
    vector<vi> g(n);
    for (int i = 0; i < n - 1; i++) {
        ll u, v, x;
        cin >> u >> v >> x;
        u--, v--;
        adj[u].eb(i);
        adj[v].eb(i);
        g[u].eb(v);
        g[v].eb(u);
        edges.eb(Edge(u, v, x));
    }
    pre_dfs(0);
    dfs_hld(0);
    val[0] = 1;
    stree.build(val);
    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            ll a, b, y;
            cin >> a >> b >> y;
            a--, b--;
            node res = path_query(a, b);
            y /= res.val;
            if (res.val == -1) y = 0;
            cout << y << '\n';
        }
        if (t == 2) {
            ll p, c;
            cin >> p >> c;
            p = edges[--p].h;
            stree.update(in[p], c);
        }
    }
}
