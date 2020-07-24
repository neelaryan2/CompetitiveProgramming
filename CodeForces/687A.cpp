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
vector<int> col;
vector<vi> adj;
void dfs(int v, int c = 0) {
    col[v] = c;
    for (int u : adj[v]) {
        if (col[u] != -1) {
            if (col[u] == c) {
                cout << "-1\n";
                exit(0);
            }
            continue;
        }
        dfs(u, c ^ 1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    col.assign(n, -1);
    for (int i = 0; i < n; i++)
        if (col[i] == -1) dfs(i);
    trace(adj);
    vector<int> ans[2];
    for (int i = 0; i < n; i++)
        ans[col[i]].eb(i + 1);
    for (int j : {0, 1}) {
        cout << ans[j].size() << '\n';
        for (int i : ans[j]) cout << i << ' ';
        cout << '\n';
    }
}
