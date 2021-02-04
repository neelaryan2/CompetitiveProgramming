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
using ppi = pair<int, pii>;
using vi = vector<int>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const ll inf = 1e18;

vector<int> siz, par;
vector<vector<pii>> adj;
int root(int a) {
    if (par[a] == -1) par[a] = a;
    int _a = a;
    while (a != par[a]) a = par[a];
    par[_a] = a;
    return a;
}
bool add(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return false;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b];
    par[b] = a;
    return true;
}
void dijkstra(int s, vector<ll>& dist) {
    int n = adj.size();
    using pi = pair<ll, int>;
    priority_queue<pi> q;
    dist.assign(n, inf);
    q.push(mp(0, s));
    dist[s] = 0;
    while (!q.empty()) {
        int v = q.top().second;
        ll d = -q.top().first;
        q.pop();
        if (d > dist[v]) continue;
        for (pii p : adj[v]) {
            int u = p.first;
            if (dist[v] + p.second < dist[u]) {
                dist[u] = dist[v] + p.second;
                q.push(mp(-dist[u], u));
            }
        }
    }
}
void bfs(int s, vector<ll>& dist) {
    int n = adj.size();
    queue<int> q;
    dist.assign(n, inf);
    vector<bool> vis(n, false);
    vis[s] = true;
    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (pii p : adj[v]) {
            int u = p.first;
            if (vis[u]) continue;
            dist[u] = dist[v] + p.second;
            vis[u] = true;
            q.push(u);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<vi> d(n, vi(n));
    vector<ppi> vec;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
            if (j > i) vec.pb(mp(d[i][j], mp(i, j)));
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                if (d[i][j] != 0) {
                    puts("NO");
                    return 0;
                }
            } else if (d[i][j] != d[j][i]) {
                puts("NO");
                return 0;
            } else if (d[i][j] == 0) {
                puts("NO");
                return 0;
            }
        }
    }
    sort(all(vec));
    siz.assign(n, 1);
    par.assign(n, -1);
    adj.resize(n);
    for (ppi p : vec) {
        bool b = add(p.se.fi, p.se.se);
        if (!b) continue;
        adj[p.se.se].eb(p.se.fi, p.fi);
        adj[p.se.fi].eb(p.se.se, p.fi);
    }
    vector<vector<ll>> nd(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
        bfs(i, nd[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (nd[i][j] != d[i][j]) {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
}
