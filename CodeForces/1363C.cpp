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
int siz[1005];
void dfs(int v, int p) {
    siz[v] = 1;
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);
        siz[v] += siz[u];
    }
}
void solve() {
    int n, x;
    cin >> n >> x;
    x--;
    adj.clear();
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int d = adj[x].size();
    if (d <= 1) {
        puts("Ayush");
        return;
    }
    if (n % 2)
        puts("Ashish");
    else
        puts("Ayush");
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
