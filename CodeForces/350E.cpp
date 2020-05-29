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
int n, m, k;
vector<bool> vis;
vector<vi> adj, take, bad;
vector<pii> vec;
void dfs(int v) {
    vis[v] = true;
    for (int u = 0; u < n; u++) {
        if (vis[u] || !adj[v][u]) continue;
        dfs(u);
        take[u][v] = 1;
        take[v][u] = 1;
        vec.eb(u, v);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    if (k >= n || m > (n * (n - 1)) / 2 - k + 1) {
        cout << "-1\n";
        return 0;
    }
    vector<int> a(k);
    vis.assign(n, false);
    adj.assign(n, vi(n, 1));
    take.assign(n, vi(n, 0));
    bad.assign(n, vi(n, 0));
    for (int i = 0; i < k; i++)
        cin >> a[i], a[i]--;
    int ref = a[0];
    for (int i = 1; i < k; i++) {
        adj[ref][a[i]] = 0;
        bad[ref][a[i]] = 1;
        adj[a[i]][ref] = 0;
        bad[a[i]][ref] = 1;
    }
    dfs(0);
    trace(vec);
    for (pii p : vec) {
        cout << p.fi + 1 << ' ' << p.se + 1 << '\n';
        m--;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (take[i][j]) continue;
            if (bad[i][j]) continue;
            if (m == 0) break;
            cout << i + 1 << ' ' << j + 1 << '\n';
            m--;
        }
        if (m == 0) break;
    }
}
