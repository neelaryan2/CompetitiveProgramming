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
#define rall(v) (v).rbegin(), (v).rend()

const int inf = 1e9 + 7;
using ar = array<int, 3>;

vector<vi> adj;
vector<int> path;

int bfs(int s) {
    int n = adj.size();
    queue<int> q;
    vector<int> dist(n, inf), par(n, -1);
    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (dist[u] != inf) continue;
            par[u] = v;
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }
    if (dist[n - 1] == inf)
        return -1;
    path.clear();
    int v = n - 1;
    while (v != -1) {
        path.eb(v);
        v = par[v];
    }
    reverse(all(path));
    return dist[n - 1];
}

void solve(int test) {
    int n, m, d;
    cin >> n >> m >> d;

    vector<vi> edges;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.pb({w, u, v});
    }

    sort(all(edges), [](vi& a, vi& b) {
        return a[0] < b[0];
    });

    int ans = -1;
    auto check = [&](int x) {
        adj.assign(n, {});
        for (vi& e : edges) {
            if (e[0] > x) break;
            adj[e[1]].eb(e[2]);
        }
        ans = bfs(0);
        return (ans != -1) && (ans <= d);
    };

    int l = -1, r = 1e9, mid;
    while (l < r - 1) {
        mid = l + (r - l) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    if (!check(r)) {
        ans = -1;
        path.clear();
    }
    cout << ans << '\n';
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
