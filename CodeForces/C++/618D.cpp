#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).rbegin(), (v).rend()
const int inf = 1e9;
vector<vi> adj;
pii dfs(int v, int p = -1) {
    int tot = 0;
    vector<int> vec;
    for (int u : adj[v]) {
        if (u == p) continue;
        pii q = dfs(u, v);
        vec.pb(1 - q.se + q.fi);
        tot += q.se;
    }
    pii c = {tot, tot};
    sort(all(vec));
    if (vec.size() == 0) return c;
    c.fi += max(0, vec[0]);
    c.se += max(0, vec[0]);
    if (vec.size() == 1) return c;
    c.se += max(0, vec[1]);
    return c;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x, y;
    cin >> n >> x >> y;
    adj.resize(n);
    vector<int> deg(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
        deg[u]++, deg[v]++;
    }
    ll ans = 0;
    if (x < y) {
        pii p = dfs(0);
        int mx = max(p.fi, p.se);
        ans = 1LL * mx * x + 1LL * (n - mx - 1) * y;
    } else {
        ans = 1LL * (n - 1) * y;
        bool flag = false;
        for (int i = 0; i < n; i++)
            if (deg[i] == n - 1)
                flag = true;
        if (flag) ans += x - y;
    }
    cout << ans << '\n';
}
