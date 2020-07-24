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
void solve(int test) {
    int n, k;
    cin >> n >> k;
    vector<vi> adj(n);
    vector<int> deg(n, 0), leaves(n, 0);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].eb(v);
        adj[v].eb(u);
        deg[u]++, deg[v]++;
    }
    if (k == 1) {
        cout << n - 1 << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
        if (deg[i] == 1)
            leaves[adj[i][0]]++;
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (leaves[i] >= k) q.push(i);
    int ans = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        int t = leaves[v] / k;
        leaves[v] -= k * t;
        deg[v] -= k * t;
        ans += t;
        if (deg[v] == 1)
            for (int u : adj[v])
                if (++leaves[u] == k)
                    q.push(u);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
