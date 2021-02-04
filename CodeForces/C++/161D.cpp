/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
vector<vi> adj;
int dp[50005][505];
int n, k;
ll ans = 0;
void dfs1(int v, int p) {
    dp[v][0] = 1;
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs1(u, v);
        for (int i = 0; i <= k; i++) {
            dp[v][i + 1] += dp[u][i];
        }
    }
}
void dfs2(int v, int p) {
    ans += dp[v][k];
    for (int u : adj[v]) {
        if (u == p) continue;
        for (int i = 0; i <= k; i++)
            dp[v][i + 1] -= dp[u][i];
        for (int i = 0; i <= k; i++)
            dp[u][i + 1] += dp[v][i];
        dfs2(u, v);
        for (int i = 0; i <= k; i++)
            dp[u][i + 1] -= dp[v][i];
        for (int i = 0; i <= k; i++)
            dp[v][i + 1] += dp[u][i];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs1(0, -1);
    dfs2(0, -1);
    cout << ans / 2 << '\n';
}
