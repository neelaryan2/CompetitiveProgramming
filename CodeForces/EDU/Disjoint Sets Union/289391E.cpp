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
#define rall(v) (v).rbegin(), (v).rend()

const int inf = 1e9 + 7;

struct DSU {
    ll ans;
    vector<int> siz, par;
    DSU(int n = 0) {
        ans = 0;
        par.resize(n);
        siz.resize(n);
        for (int i = 0; i < n; i++)
            makeset(i);
    }
    void makeset(int a) {
        par[a] = a;
        siz[a] = 1;
    }
    int root(int a) {
        if (par[a] == a) return a;
        return par[a] = root(par[a]);
    }
    void unite(pii p, int w) {
        int a = root(p.fi), b = root(p.se);
        if (a == b) return;
        if (siz[a] > siz[b])
            swap(a, b);
        siz[b] += siz[a];
        par[a] = b;
        ans += w;
    }
};
void solve(int test) {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);

    vector<ppi> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.pb(mp(w, mp(u, v)));
    }
    sort(all(edges));
    for (auto e : edges)
        dsu.unite(e.se, e.fi);
    cout << dsu.ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
    }
}
