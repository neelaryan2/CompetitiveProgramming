/* Author - Neel Aryan (@neelaryan2) */
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
vector<int> a, b, c, notone, notzero;
ll dfs(int v, int mn, int p) {
    mn = min(mn, a[v]);
    notone[v] = 0, notzero[v] = 0;
    ll res = 0;
    if (b[v] && !c[v]) notzero[v]++;
    if (!b[v] && c[v]) notone[v]++;
    for (int u : adj[v]) {
        if (u == p) continue;
        ll cur = dfs(u, mn, v);
        res += cur;
        notone[v] += notone[u];
        notzero[v] += notzero[u];
    }
    trace(v, notone[v], notzero[v]);
    int mn2 = min(notzero[v], notone[v]);
    notzero[v] -= mn2;
    notone[v] -= mn2;
    res += 2LL * mn * mn2;
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    notzero.resize(n);
    notone.resize(n);
    adj.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    trace(n, adj);
    ll ans = dfs(0, 1e9, -1);
    if (notone[0] || notzero[0]) ans = -1;
    cout << ans << '\n';
}
