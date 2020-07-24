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
int n;
vector<vector<int>> adj;
vector<int> siz;
vector<bool> ans;
void dfs(int v, int p = -1) {
    vector<int> a;
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);
        siz[v] += siz[u];
        a.eb(siz[u]);
    }
    vector<bool> dp(n, false);
    dp[n - siz[v]] = true;
    for (int e : a) {
        for (int j = n - 1; j >= 0; j--)
            if (dp[j] && j + e < n) dp[j + e] = true;
        dp[e] = true;
    }
    for (int i = 1; i < n - 1; i++)
        if (dp[i]) ans[i] = true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    adj.resize(n);
    ans.assign(n, false);
    siz.assign(n, 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    dfs(0);
    cout << accumulate(all(ans), 0) << '\n';
    for (int i = 0; i < n; i++)
        if (ans[i]) cout << i << ' ' << n - i - 1 << '\n';
}
