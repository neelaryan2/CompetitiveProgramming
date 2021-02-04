#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const int inf = 1e9;
vi bfs(int s, vector<vi>& g) {
    int n = g.size();
    vi dist(n, inf);
    vector<bool> vis(n, false);
    queue<int> q;
    vis[s] = true;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
            if (vis[u]) continue;
            dist[u] = dist[v] + 1;
            vis[u] = true;
            q.push(u);
        }
    }
    return dist;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vi> nadj(n), adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        nadj[v].pb(u);
    }
    int k;
    cin >> k;
    stack<int> path;
    for (int i = 0; i < k; i++) {
        int e;
        cin >> e;
        path.push(--e);
    }
    int prv = path.top();
    vi dist = bfs(prv, nadj);
    path.pop();
    int mnans = 0, mxans = 0;
    while (!path.empty()) {
        int v = path.top();
        path.pop();
        int mn = inf, cnt = 0;
        for (int u : adj[v]) {
            mn = min(mn, dist[u]);
        }
        for (int u : adj[v]) {
            if (dist[u] == mn)
                cnt++;
        }
        if (dist[prv] != mn) {
            mxans++;
            mnans++;
        } else if (cnt > 1) {
            mxans++;
        }
        prv = v;
    }
    cout << mnans << " " << mxans << "\n";
}