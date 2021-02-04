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
vector<vi> adj;
vector<int> tin, tout, dep;
int T = 0;
void dfs(int v, int p = -1, int d = 1) {
    tin[v] = T++;
    dep[v] = d;
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs(u, v, d + 1);
    }
    tout[v] = T - 1;
}
struct segtree {
    vector<ll> t, d;
    int n, h;
    segtree(int m) {
        n = m;
        h = 32 - __builtin_clz(n);
        d.assign(n, 0);
        t.assign(2 * n, 0);
    }
    void apply(int p, ll value) {
        t[p] += value;
        if (p < n) d[p] += value;
    }
    void build(int p) {
        while (p >>= 1)
            t[p] = t[p << 1] + t[p << 1 | 1] + d[p];
    }
    void push(int p) {
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
        l += n, r += n + 1;
        int _l = l, _r = r;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) apply(l++, value);
            if (r & 1) apply(--r, value);
        }
        build(_l), build(_r - 1);
    }
    ll query(int l, int r) {
        l += n, r += n + 1;
        push(l), push(r - 1);
        ll res = 0;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += t[l++];
            if (r & 1) res += t[--r];
        }
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    tin.resize(n);
    tout.resize(n);
    dep.resize(n);
    vector<int> a(n);
    for (int& e : a) cin >> e;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    dfs(0);
    segtree tree = segtree(n);
    for (int i = 0; i < m; i++) {
        int t, x;
        cin >> t >> x;
        x--;
        if (t == 1) {
            int val;
            cin >> val;
            if (dep[x] & 1) val *= -1;
            tree.add(tin[x], tout[x], val);
        } else if (t == 2) {
            int ans = tree.query(tin[x], tin[x]);
            if (dep[x] & 1) ans *= -1;
            cout << ans + a[x] << '\n';
        }
    }
}
