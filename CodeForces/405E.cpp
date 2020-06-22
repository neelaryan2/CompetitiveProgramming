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
using ppi = pair<pii, int>;
using vi = vector<int>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
vector<bool> vis;
vector<vector<pii>> adj;
vector<ppi> ans;
int dfs(int v) {
    vector<int> ext;
    for (pii p : adj[v]) {
        int u = p.fi;
        if (vis[p.se]) continue;
        vis[p.se] = true;
        int w = dfs(u);
        if (w == -1)
            ext.eb(u);
        else
            ans.eb(mp(mp(v, u), w));
    }
    int k = ext.size();
    for (int i = 1; i < k; i += 2)
        ans.eb(mp(mp(ext[i - 1], v), ext[i]));
    if (k & 1) return ext.back();
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    if (m & 1) {
        cout << "No solution\n";
        return 0;
    }
    adj.resize(n);
    vis.assign(m, false);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].eb(v, i);
        adj[v].eb(u, i);
    }
    dfs(0);
    for (auto p : ans)
        cout << p.fi.fi + 1 << ' ' << p.fi.se + 1 << ' ' << p.se + 1 << '\n';
}
