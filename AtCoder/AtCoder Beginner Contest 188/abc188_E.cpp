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

vector<vi> adj;
vector<int> a, mx;
vector<bool> vis;
int ans;

void dfs(int v, int mn) {
    mn = min(mn, a[v]);
    mx[v] = a[v];
    vis[v] = true;
    for (int u : adj[v]) {
        if (!vis[u]) dfs(u, mn);
        mx[v] = max(mx[v], mx[u]);
        ans = max(ans, mx[u] - mn);
    }
}

void solve(int test) {
    int n, m;
    ans = -inf;
    cin >> n >> m;
    mx.assign(n, -1);
    a.resize(n);
    adj.assign(n, {});
    for (int& e : a) cin >> e;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].eb(v);
    }
    vis.assign(n, false);
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        dfs(i, inf);
    }
    cout << ans;
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
        cout << '\n';
    }
}
