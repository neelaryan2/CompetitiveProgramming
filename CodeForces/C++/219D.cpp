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
vector<vector<pii>> adj;
vector<int> dp, ans;
void dfs1(int v, int pr = -1) {
    dp[v] = 0;
    for (pii p : adj[v]) {
        int u = p.fi;
        if (u == pr) continue;
        dfs1(u, v);
        dp[v] += p.se + dp[u];
    }
}
void dfs2(int v, int pr = -1) {
    ans[v] = dp[v];
    for (pii p : adj[v]) {
        int u = p.fi;
        if (u == pr) continue;
        dp[v] -= p.se + dp[u];
        dp[u] += dp[v] + 1 - p.se;
        dfs2(u, v);
        dp[u] -= dp[v] + 1 - p.se;
        dp[v] += p.se + dp[u];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    adj.resize(n);
    dp.resize(n);
    ans.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb({v, 0});
        adj[v].pb({u, 1});
    }
    dfs1(0);
    dfs2(0);
    int mn = *min_element(all(ans));
    trace(ans);
    cout << mn << '\n';
    for (int i = 0; i < n; i++) {
        if (ans[i] != mn) continue;
        cout << i + 1 << ' ';
    }
    cout << '\n';
}
