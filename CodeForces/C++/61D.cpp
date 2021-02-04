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
const ll inf = 1e18;
vector<vector<pii>> adj;
vector<ll> cost;
void dfs1(int v, int pr = -1) {
    for (pii& p : adj[v]) {
        int u = p.fi;
        if (u == pr) continue;
        dfs1(u, v);
        cost[v] += cost[u] + p.se;
    }
}
ll dfs2(int v, int pr = -1) {
    ll res = inf, cur;
    for (pii& p : adj[v]) {
        int u = p.fi;
        if (u == pr) continue;
        cur = dfs2(u, v);
        cur += 2 * (cost[v] - cost[u]) - p.se;
        res = min(res, cur);
    }
    if (res == inf) return 0;
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    adj.resize(n);
    cost.assign(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    dfs1(0);
    ll ans = dfs2(0);
    cout << ans << '\n';
}
