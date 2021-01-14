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
using pli = pair<ld, int>;
using vi = vector<int>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

using ar = array<int, 3>;
const ll inf = 1e18;

vector<vector<pli>> adj;
vector<int> path;

ld dijkstra(int s) {
    int n = adj.size();
    priority_queue<pli> pq;
    vector<ld> dist(n, inf);
    vector<int> par(n, -1);
    pq.push(mp(0, s));
    dist[s] = 0;
    while (!pq.empty()) {
        int v = pq.top().second;
        ld d = -pq.top().first;
        pq.pop();
        if (d > dist[v]) continue;
        for (pli p : adj[v]) {
            ld w = p.first;
            int u = p.second;
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                par[u] = v;
                pq.push(mp(-dist[u], u));
            }
        }
    }
    path.clear();
    int v = n - 1;
    while (v != -1) {
        path.eb(v);
        v = par[v];
    }
    if (dist[n - 1] == inf)
        path.clear();
    reverse(all(path));
    return dist[n - 1];
}

void solve(int test) {
    int n, m;
    cin >> n >> m;

    vector<pair<ld, pii>> edges;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.pb(mp(w, mp(u, v)));
    }

    ld ans = inf;
    auto check = [&](ld x) {
        adj.assign(n, {});
        for (auto& e : edges)
            adj[e.se.fi].eb(mp(e.fi - x, e.se.se));
        ans = dijkstra(0);
        return !path.empty() && ans <= 0;
    };

    ld l = 0, r = 100, mid;
    for (int i = 0; i < 30; i++) {
        mid = l + (r - l) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    assert(check(r));
    cout << (path.size() - 1) << '\n';
    for (int i : path)
        cout << i + 1 << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
    }
}
