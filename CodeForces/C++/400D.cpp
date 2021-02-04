#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<pair<int, int>, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const int inf = 1e9;
vector<vi> adj, dist;
vector<int> comp, type;
int T = 0;
void bfs(int v) {
    comp[v] = T;
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int u = q.front();
        comp[u] = T;
        q.pop();
        for (int t : adj[u]) {
            dist[type[u]][type[t]] = 0;
            if (comp[t] != -1) continue;
            q.push(t);
            comp[t] = T;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> c(k + 1, 0);
    type.resize(n);
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        c[i] += c[i - 1];
        for (int j = c[i - 1]; j < c[i]; j++)
            type[j] = i-1;
    }
    vector<pii> edges;
    adj.resize(n);
    dist.assign(k, vi(k, inf));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        if (w == 0) {
            adj[u].pb(v);
            adj[v].pb(u);
        } else
            edges.pb({{u, v}, w});
    }
    comp.assign(n, -1);
    for (int i = 0; i < k; i++) {
        int v = c[i];
        if (comp[v] == -1) {
            bfs(v);
            T++;
        }
    }
    for (int i = 0; i < k; i++) {
        int cur = comp[c[i]];
        for (int j = c[i] + 1; j < c[i + 1]; j++) {
            if (comp[j] != cur) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i < k; i++)
        dist[i][i] = 0;
    for (auto e : edges) {
        int u = comp[e.fi.fi];
        int v = comp[e.fi.se];
        int w = e.se;
        if (u == v) w = 0;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = dist[u][v];
    }
    for (int h = 0; h < k; h++) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                dist[i][j] = min(dist[i][j],
                                 dist[i][h] + dist[h][j]);
            }
        }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            int d = dist[i][j];
            if (d == inf) d = -1;
            cout << d << " ";
        }
        cout << endl;
    }
}