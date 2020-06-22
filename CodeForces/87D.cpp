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
struct Edge {
    int u, v, w, id;
    Edge() {}
    void read(int ii) {
        int uu, vv, ww;
        cin >> uu >> vv >> ww;
        u = --uu, v = --vv;
        w = ww, id = ii;
    }
    bool operator<(const Edge& e) const {
        return w < e.w;
    }
    other(int t) { return u ^ v ^ t; }
};
vector<Edge> edge;
vector<int> siz, par, siz2;
vector<ll> trees;
vector<vector<pii>> adj;
vector<bool> vis;
int root(int a) {
    if (par[a] == -1) par[a] = a;
    int _a = a;
    while (a != par[a]) a = par[a];
    par[_a] = a;
    return a;
}
void add(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b];
    par[b] = a;
}
void dfs(int v, int p = -1) {
    vis[v] = true;
    for (pii t : adj[v]) {
        int u = t.fi;
        if (u == p) continue;
        dfs(u, v);
        siz2[v] += siz2[u];
    }
}
void dfs2(int v, int tot, int p = -1) {
    for (pii t : adj[v]) {
        int u = t.fi;
        if (u == p) continue;
        dfs2(u, tot, v);
        trees[t.se] = 2LL * siz2[u] * (tot - siz2[u]);
    }
    adj[v].clear();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    edge.resize(n - 1);
    trees.resize(n - 1);
    par.resize(n, -1);
    siz.resize(n, 1);
    siz2.resize(n, 1);
    adj.resize(n);
    vis.resize(n);
    map<int, vector<Edge>> cnt;
    for (int i = 0; i < n - 1; i++) {
        edge[i].read(i);
        cnt[edge[i].w].eb(edge[i]);
    }
    for (auto p : cnt) {
        vector<int> vec;
        for (Edge e : p.se) {
            vec.eb(root(e.u));
            vec.eb(root(e.v));
        }
        sort(all(vec));
        vec.resize(unique(all(vec)) - vec.begin());
        for (Edge e : p.se) {
            int u = lb(all(vec), root(e.u)) - vec.begin();
            int v = lb(all(vec), root(e.v)) - vec.begin();
            siz2[u] = siz[root(e.u)];
            siz2[v] = siz[root(e.v)];
            adj[u].eb(v, e.id);
            adj[v].eb(u, e.id);
            vis[u] = false;
            vis[v] = false;
        }
        int k = vec.size();
        for (int i = 0; i < k; i++) {
            if (vis[i]) continue;
            dfs(i);
            int tot = siz2[i];
            dfs2(i, tot);
        }
        for (Edge e : p.se)
            add(e.u, e.v);
    }
    ll mx = *max_element(all(trees));
    vector<int> ans;
    for (int i = 0; i < n - 1; i++)
        if (trees[i] == mx) ans.eb(i + 1);
    cout << mx << ' ' << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
    cout << '\n';
}
