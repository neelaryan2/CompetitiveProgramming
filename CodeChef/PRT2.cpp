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
const int inf = 1e9 + 7;
vector<int> dist, dp;
vector<vi> adj;
void dfs(int v, int p = -1) {
    vector<int> vec;
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);
        dist[v] = min(dist[v], dist[u] + 1);
        vec.eb(dist[u]);
    }
    if (dist[v] == inf) dist[v] = 1;
    if (vec.size() <= 1) return;
    sort(all(vec));
    dp[v] = 1 + vec[0] + vec[1];
}
void solve(int test) {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll& e : a) cin >> e;
    sort(all(a));
    reverse(all(a));
    adj.assign(n, {});
    dp.assign(n, inf);
    dist.assign(n, inf);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    trace(adj);
    int root = 0;
    for (int i = 0; i < n; i++)
        if (adj[i].size() > 1u) root = i;
    dfs(root);
    int lvl = *min_element(all(dp));
    if (n == 2) lvl = 2;
    ll ans = 0;
    ll q = k / (2 * lvl), r = k % (2 * lvl);
    for (int i = 0; i < lvl; i++)
        ans += a[i];
    ans *= 2 * q;
    if (r & 1) {
        for (int i = 0; i < r / 2; i++)
            ans += 2 * a[i];
        ans += a[r / 2];
    } else {
        if (r == 2) {
            ans += a[0] + a[1];
        } else {
            for (int i = 0; i < r / 2; i++)
                ans += 2 * a[i];
        }
    }
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
        cout << "\n";
    }
}
