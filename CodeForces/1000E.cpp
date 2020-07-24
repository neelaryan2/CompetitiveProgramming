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
int n, m, timer, cnt, T;
vector<vector<int>> adj;
vector<bool> visited, bridges;
vector<int> tin, low, comp;
vector<pii> edges;
void dfs(int v, int p = -1) {
    comp[v] = T;
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int id : adj[v]) {
        int to = v ^ edges[id].fi ^ edges[id].se;
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                bridges[id] = true;
        }
    }
}
void find_bridges() {
    timer = cnt = T = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    comp.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
            T++, cnt++;
        }
    }
}
vector<int> bfs(int s) {
    queue<int> q;
    vector<bool> vis(T, false);
    vector<int> d(T, 1e9);
    q.push(s);
    vis[s] = true;
    d[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (vis[u]) continue;
            vis[u] = true;
            d[u] = d[v] + 1;
            q.push(u);
        }
    }
    return d;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    adj.resize(n);
    edges.resize(m);
    bridges.assign(m, false);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (u > v) swap(u, v);
        adj[u].eb(i);
        adj[v].eb(i);
        edges[i] = mp(u, v);
    }
    find_bridges();
    assert(cnt == 1);
    adj.clear();
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        if (bridges[i]) continue;
        pii p = edges[i];
        adj[p.fi].eb(i);
        adj[p.se].eb(i);
    }
    find_bridges();
    adj.clear();
    adj.resize(T);
    for (int i = 0; i < m; i++) {
        if (!bridges[i]) continue;
        pii p = edges[i];
        p.fi = comp[p.fi];
        p.se = comp[p.se];
        adj[p.fi].eb(p.se);
        adj[p.se].eb(p.fi);
    }
    vector<int> d = bfs(0);
    int x = max_element(all(d)) - d.begin();
    d = bfs(x);
    cout << *max_element(all(d)) << '\n';
}
