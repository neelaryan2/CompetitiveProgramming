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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    set<pii> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (u > v) swap(u, v);
        edges.insert(mp(u, v));
    }
    int inf = 1e9;
    vector<vector<int>> adj[2];
    queue<int> q[2];
    vector<int> d[2];
    vector<bool> vis[2];
    for (int i : {0, 1}) {
        d[i].assign(n, inf);
        vis[i].assign(n, false);
        adj[i].resize(n);
        d[i][0] = 0;
        q[i].push(0);
        vis[i][0] = true;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            pii p = mp(i, j);
            if (edges.find(p) == edges.end()) {
                adj[0][i].eb(j);
                adj[0][j].eb(i);
            } else {
                adj[1][i].eb(j);
                adj[1][j].eb(i);
            }
        }
    }
    while (!q[0].empty() || !q[1].empty()) {
        set<int> nodes[2];
        for (int t : {0, 1}) {
            if (q[t].empty()) continue;
            int v = q[t].front();
            q[t].pop();
            for (int u : adj[t][v]) {
                if (vis[t][u]) continue;
                d[t][u] = d[t][v] + 1;
                vis[t][u] = true;
                nodes[t].insert(u);
            }
        }
        for (int t : {0, 1})
            for (int v : nodes[t])
                if (nodes[t ^ 1].find(v) == nodes[t ^ 1].end())
                    q[t].push(v);
    }
    int ans = max(d[0][n - 1], d[1][n - 1]);
    if (ans == inf) ans = -1;
    cout << ans << '\n';
}
