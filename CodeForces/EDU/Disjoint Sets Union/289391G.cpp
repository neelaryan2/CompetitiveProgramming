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
using ppi = pair<ll, pii>;
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

const ll inf = 1e11;

struct DSU {
    int comp;
    vector<int> siz, par;
    DSU(int n = 0) {
        comp = n;
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
    void unite(int a, int b) {
        a = root(a), b = root(b);
        if (a == b) return;
        if (siz[a] > siz[b])
            swap(a, b);
        siz[b] += siz[a];
        par[a] = b;
        comp--;
    }
};
void solve(int test) {
    int n, m;
    cin >> n >> m;

    vector<ppi> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.pb(mp(w, mp(u, v)));
    }
    sort(all(edges));

    ll ans = -1;
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        ppi e = edges[i];
        dsu.unite(e.se.fi, e.se.se);
        if (dsu.comp == 1) {
            ans = e.fi;
            break;
        }
    }
    assert(ans != -1);
    cout << ans << '\n';
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
