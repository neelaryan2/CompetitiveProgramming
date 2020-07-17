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
using pli = pair<ll, int>;
using vi = vector<int>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
using ll = long long;
const ll inf = 1e18;
using pli = pair<ll, int>;
vector<ll> dist;
vector<vector<pli>> adj;
void dijkstra(int s) {
    int n = adj.size();
    priority_queue<pli> pq;
    dist.assign(n, inf);
    pq.push(make_pair(0, s));
    dist[s] = 0;
    while (!pq.empty()) {
        int v = pq.top().second;
        ll d = -pq.top().first;
        pq.pop();
        if (d > dist[v]) continue;
        for (pli p : adj[v]) {
            ll w = p.first;
            int u = p.second;
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                // par[u] = v;
                pq.push(make_pair(-dist[u], u));
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    adj.resize(++n);
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        w <<= 1;
        adj[u].eb(w, v);
        adj[v].eb(w, u);
    }
    for (int i = 1; i < n; i++) {
        ll a;
        cin >> a;
        adj[0].eb(a, i);
        adj[i].eb(a, 0);
    }
    dijkstra(0);
    for (int i = 1; i < n; i++)
        cout << dist[i] << ' ';
    cout << '\n';
}
