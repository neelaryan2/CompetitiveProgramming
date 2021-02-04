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
vector<vi> adj;
vector<bool> vis;
int cnt;
void dfs(int v) {
    vis[v] = true;
    cnt++;
    for (int u : adj[v]) {
        if (vis[u]) continue;
        dfs(u);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    vis.assign(n, false);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        cnt = 0;
        dfs(i);
        ans += (1LL * cnt * (cnt - 1)) / 2;
    }
    puts((ans == m) ? "YES" : "NO");
}
