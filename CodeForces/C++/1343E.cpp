#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pii>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const ll inf = LLONG_MAX;
vi bfs(int b, vector<vi>& adj) {
    int n = adj.size();
    queue<int> q;
    vi dist(n, inf), par(n, -1);
    vector<bool> vis(n, false);
    q.push(b);
    vis[b] = true;
    dist[b] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (vis[u]) continue;
            par[u] = v;
            dist[u] = dist[v] + 1;
            q.push(u);
            vis[u] = true;
        }
    }
    return dist;
}
void solve() {
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    a--;
    b--;
    c--;
    vector<ll> p(m);
    for (ll& e : p) cin >> e;
    p.pb(0);
    sort(all(p));
    for (int i = 1; i <= m; i++)
        p[i] += p[i - 1];
    vector<vi> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi dista = bfs(a, adj);
    vi distb = bfs(b, adj);
    vi distc = bfs(c, adj);
    ll ans = inf;
    for (int i = 0; i < n; i++) {
        int da = dista[i];
        int db = distb[i];
        int dc = distc[i];
        if (da + db + dc <= m) {
            ans = min(ans, p[da + db + dc] + p[db]);
        }
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}