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
using vpi = vector<pii>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

const ll inf = 1e18 + 7;
vector<vi> adj, nodes;
vector<ll> a, par;

void dfs(int v, int p = -1, int d = 0) {
    par[v] = p;
    if (d == nodes.size())
        nodes.eb();
    nodes[d++].eb(v);
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs(u, v, d);
    }
}
void solve(int test) {
    int n;
    cin >> n;
    adj.assign(n, {});
    nodes.clear();
    for (int i = 1, v; i < n; i++) {
        cin >> v, v--;
        adj[v].eb(i);
        adj[i].eb(v);
    }
    a.assign(n, 0);
    par.resize(n);
    for (int i = 1; i < n; i++)
        cin >> a[i];
    dfs(0);
    vector<ll> dp(n, -inf);
    dp[0] = 0;
    for (int i = 1; i < nodes.size(); i++) {
        vi& cur = nodes[i];
        ll minuss = -inf, pluss = -inf;
        ll mxa = -inf, mna = inf;
        for (int& u : cur) {
            int v = par[u];
            mxa = max(mxa, a[u]);
            mna = min(mna, a[u]);
            pluss = max(pluss, dp[v] + a[u]);
            minuss = max(minuss, dp[v] - a[u]);
        }
        for (int& u : cur) {
            int v = par[u], mx = max(abs(mna - a[u]), abs(mxa - a[u]));
            dp[u] = max({dp[v] + mx, pluss - a[u], minuss + a[u]});
        }
    }
    ll ans = *max_element(all(dp));
    cout << ans;
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
