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
using ppi = pair<pii, int>;
using vi = vector<int>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const int inf = 1e9 + 7;
int T;
vector<int> dist, parent, nodes;
vector<vector<pii>> adj;
void dijkstra(int s) {
    int n = adj.size();
    priority_queue<ppi> q;
    dist.assign(n, inf);
    nodes.assign(n, 0);
    parent.assign(n, -1);
    q.push(mp(mp(1, 0), s));
    dist[s] = 0;
    while (!q.empty()) {
        int k = q.top().fi.fi;
        int v = q.top().se;
        int d = -q.top().fi.se;
        q.pop();
        trace(v);
        if (k > nodes[v]) continue;
        for (pii p : adj[v]) {
            int u = p.first, w = p.second;
            if (dist[v] + w > T) continue;
            if (nodes[v] + 1 < nodes[u]) {
                dist[u] = dist[v] + w;
                nodes[u] = nodes[v] + 1;
                parent[u] = v;
                q.push(mp(mp(nodes[u], -dist[u]), u));
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m >> T;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        u--, v--;
        adj[u].eb(v, t);
        adj[v].eb(u, t);
    }
    dijkstra(0);
    int v = n - 1;
    vector<int> ans;
    while (v)
        ans.eb(v + 1), v = parent[v];
    ans.eb(1);
    reverse(all(ans));
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
    cout << '\n';
}
