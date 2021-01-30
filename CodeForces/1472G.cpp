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

vector<bool> vis[2];
vector<int> dp[2], d;
vector<vi> adj;

void dfs(int v, int tv) {
    vis[tv][v] = true;
    dp[tv][v] = d[v];
    for (int u : adj[v]) {
        if (d[u] > d[v]) {
            if (!vis[tv][u]) dfs(u, tv);
            dp[tv][v] = min(dp[tv][v], dp[tv][u]);
        } else if (!tv) {
            if (!vis[1][u]) dfs(u, 1);
            dp[tv][v] = min(dp[tv][v], dp[1][u]);
        }
    }
}
void solve(int test) {
    int n, m;
    cin >> n >> m;

    adj.assign(n, {});
    for (int i : {0, 1}) {
        vis[i].assign(n, false);
        dp[i].assign(n, inf);
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].eb(v);
    }

    queue<int> q;
    d.assign(n, inf);
    d[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (d[u] > d[v] + 1) {
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!vis[0][i]) dfs(i, 0);
        cout << dp[0][i] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << '\n';
    }
}
