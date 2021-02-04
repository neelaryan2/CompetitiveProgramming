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
vector<int> p, h;
vector<vi> adj;
bool bad;
void dfs(int v, int par = -1) {
    ll res = 0, sum = 0;
    for (int u : adj[v]) {
        if (u == par) continue;
        dfs(u, v);
        res += h[u];
        sum += p[u];
    }
    if (h[v] + p[v] < res || ((p[v] + h[v] - res) & 1) || h[v] > p[v] + sum) {
        bad = true;
        return;
    }
    p[v] += sum;
}
void solve(int test) {
    int n, m;
    cin >> n >> m;
    p.resize(n);
    h.resize(n);
    bad = false;
    adj.assign(n, {});
    for (int& e : p) cin >> e;
    for (int& e : h) cin >> e;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    dfs(0);
    cout << (bad ? "NO" : "YES");
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
