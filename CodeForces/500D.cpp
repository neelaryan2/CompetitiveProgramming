#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using ppi = pair<pii, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
vector<ppi> edges;
vector<vi> adj;
vector<ll> siz;
vector<ld> coeff;
ld ans = 0, denom;
int root = 0;
ll get(ll num) {
    return (1LL * num * (num - 1)) / 2;
}
void dfs1(int v, int p = -1) {
    for (int i : adj[v]) {
        pii pe = edges[i].fi;
        int u = pe.fi ^ pe.se ^ v;
        if (u == p) continue;
        dfs1(u, v);
        siz[v] += siz[u];
    }
}
void dfs2(int v, int p = -1) {
    for (int i : adj[v]) {
        pii pe = edges[i].fi;
        int u = pe.fi ^ pe.se ^ v;
        if (u == p) continue;
        dfs2(u, v);
        ld& res = coeff[i];
        ll a = siz[u], b = siz[root] - siz[u];
        res += ((ld)2 * get(a) * b) / denom;
        res += ((ld)2 * get(b) * a) / denom;
        ans += res * edges[i].se;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    denom = (get(n) * (n - 2)) / 3;
    edges.resize(n - 1);
    coeff.assign(n - 1, 0);
    siz.assign(n, 1);
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges[i] = {{u, v}, w};
        adj[u].pb(i);
        adj[v].pb(i);
    }
    dfs1(root);
    dfs2(root);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int p, now;
        cin >> p >> now;
        int was = edges[--p].se;
        ans += (ld) (now - was) * coeff[p];
        edges[p].se = now;
        cout << fixed << setprecision(10) << ans << '\n';
    }
}
