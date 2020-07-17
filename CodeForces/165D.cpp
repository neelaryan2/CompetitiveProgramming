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
    int u, v, in;
    Edge(int uu = -1, int vv = -1) {
        u = uu, v = vv, in = -1;
    }
    int get(int t) { return t ^ u ^ v; }
};
int T = 0;
vector<Edge> edges;
vector<vector<int>> adj;
vector<int> in, up, down, siz, par, depth, deg;
void init(int n) {
    siz.assign(n, 1);
    deg.assign(n, 0);
    up.resize(n);
    iota(up.begin(), up.end(), 0);
    down.resize(n);
    iota(down.begin(), down.end(), 0);
    adj.resize(n);
    in.resize(n);
    par.resize(n);
    depth.resize(n);
    edges.resize(n - 1);
}
void pre_dfs(int v = 0, int p = -1, int d = 0) {
    depth[v] = d, par[v] = p;
    for (int& i : adj[v]) {
        int u = edges[i].get(v);
        if (u == p) continue;
        int r = edges[adj[v][0]].get(v);
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
        if (u == p) continue;
        if (i == adj[v][0]) up[u] = up[v];
        dfs_hld(u, v);
        edges[i].in = in[u];
        if (i == adj[v][0]) down[v] = down[u];
    }
}
vector<int> B;
void add(vector<int>& B, int i, int x) {
    int n = B.size();
    for (; i < n; i += i & (-i))
        B[i] = B[i] + x;
}
int sum(vector<int>& B, int i) {
    int sum = 0;
    for (; i > 0; i -= i & (-i))
        sum = sum + B[i];
    return sum;
}
int path_query(int a, int b) {
    int res = 0, dist = 0;
    for (; up[a] != up[b]; b = par[up[b]]) {
        if (depth[up[a]] > depth[up[b]]) swap(a, b);
        dist += depth[b] - depth[up[b]] + 1;
        // (in[up[b]], in[b]) is the segment
        res += sum(B, in[b] + 1) - sum(B, in[up[b]]);
    }
    if (depth[a] > depth[b]) swap(a, b);
    // (in[a], in[b]) is the segment
    res += sum(B, in[b] + 1) - sum(B, in[a] + 1);
    dist += depth[b] - depth[a];
    if (res) dist = -1;
    return dist;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    init(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].eb(i);
        adj[v].eb(i);
        edges[i] = Edge(u, v);
        deg[u]++, deg[v]++;
    }
    int root = max_element(all(deg)) - deg.begin();
    pre_dfs(root);
    dfs_hld(root);
    B.assign(n + 10, 0);
    trace(in);
    int m;
    cin >> m;
    while (m--) {
        int t, u, v;
        cin >> t;
        if (t <= 2) {
            cin >> v;
            int c = (t == 2) ? 1 : -1;
            add(B, edges[v - 1].in + 1, c);
        }
        if (t == 3) {
            cin >> u >> v;
            u--, v--;
            int res = path_query(u, v);
            cout << res << '\n';
        }
    }
}
