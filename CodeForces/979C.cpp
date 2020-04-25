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
#define all(v) (v).begin(), (v).end()
int n, x, y;
vector<vi> adj;
vi siz;
bool dfs(int v, int p) {
    bool b = (v == y);
    for (int u : adj[v]) {
        if (u == p) continue;
        bool f = dfs(u, v);
        siz[v] += siz[u];
        b = b || f;
    }
    return b;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> x >> y;
    x--, y--;
    adj.resize(n);
    siz.assign(n, 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int u : adj[x]) {
        if (!dfs(u, x))
            siz[x] += siz[u];
    }
    ll ans = 1LL * siz[x] * siz[y];
    ans = 1LL * n * (n - 1) - ans;
    cout << ans << endl;
}