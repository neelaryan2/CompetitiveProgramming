/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<int, int>;
using ppi = pair<ll, pii>;
using vi = vector<ll>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const ll inf = 1e18;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    int root = 0;
    cin >> n >> m >> k;
    vector<vector<ppi>> adj(n);
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].pb(mp(w, mp(v, 1)));
        adj[v].pb(mp(w, mp(u, 1)));
    }
    for (int i = 0; i < k; i++) {
        ll s, y;
        cin >> s >> y;
        s--;
        adj[root].pb(mp(y, mp(s, 0)));
        adj[s].pb(mp(y, mp(root, 0)));
    }
    vector<bool> vis(n, false);
    priority_queue<ppi> q;
    q.push(mp(0, mp(root, 1)));
    int important = 0;
    while (!q.empty()) {
        ppi t = q.top();
        q.pop();
        int v = t.se.fi;
        int type = t.se.se;
        if (vis[v]) continue;
        vis[v] = true;
        if (type == 0) important++;
        for (ppi p : adj[v])
            if (!vis[p.se.fi])
                q.push(mp(t.fi - p.fi, p.se));
    }
    cout << k - important << '\n';
}
