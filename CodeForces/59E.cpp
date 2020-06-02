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
using ppi = pair<int, pii>;
using vi = vector<int>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const int inf = 1e9;
set<ppi> dont;
vector<vi> adj;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;
        dont.insert(mp(a, mp(b, c)));
    }
    queue<pii> q;
    q.push(mp(0, 0));
    vector<vi> dist(n, vi(n, inf));
    vector<vi> par(n, vi(n, -1));
    dist[0][0] = 0;
    while (!q.empty()) {
        int v = q.front().fi;
        int p = q.front().se;
        q.pop();
        for (int u : adj[v]) {
            ppi t = mp(p, mp(v, u));
            int cur = dist[p][v] + 1;
            if (dont.find(t) != dont.end()) continue;
            if (dist[v][u] <= cur) continue;
            q.push(mp(u, v));
            dist[v][u] = cur;
            par[v][u] = p;
        }
    }
    trace(par);
    trace(dist);
    int mn = inf;
    vector<int> ans;
    int v2 = n - 1, v1 = -1;
    for (int i = 0; i < n; i++) {
        if (dist[i][n - 1] < mn) {
            mn = dist[i][n - 1];
            v1 = i;
        }
    }
    if (v1 == -1) {
        cout << "-1\n";
        return 0;
    }
    while (v1 != -1) {
        ans.pb(v2 + 1);
        int p = par[v1][v2];
        v2 = v1;
        v1 = p;
    }
    reverse(all(ans));
    cout << ans.size() - 1 << '\n';
    for (int i : ans) cout << i << " ";
    cout << '\n';
}
