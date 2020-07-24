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
struct Edge {
    int u, v;
    ll w;
    Edge(int uu = -1, int vv = -1, ll ww = -1) { u = uu, v = vv, w = ww; }
    bool operator<(const Edge& oth) { return w < oth.w; }
    int get(int t) { return t ^ u ^ v; }
};
vector<Edge> edges;
vector<int> siz, par;
int root(int a) {
    int _a = a;
    while (a != par[a]) a = par[a];
    par[_a] = a;
    return a;
}
bool add(int a, int b) {
    a = root(a), b = root(b);
    if (a == b) return false;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b];
    par[b] = a;
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<ll> c(n);
    for (ll& e : c) cin >> e;
    int s = min_element(all(c)) - c.begin();
    for (int i = 0; i < n; i++) {
        if (i == s) continue;
        edges.eb(Edge(s, i, c[s] + c[i]));
    }
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.eb(Edge(u, v, w));
    }
    siz.assign(n, 1);
    par.resize(n);
    iota(all(par), 0);
    sort(all(edges));
    ll ans = 0;
    for (Edge& e : edges)
        if (add(e.u, e.v))
            ans += e.w;
    cout << ans << '\n';
}
