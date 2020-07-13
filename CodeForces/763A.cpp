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
vector<int> siz, par;
int root(int a) {
    if (par[a] == -1) par[a] = a;
    int _a = a;
    while (a != par[a]) a = par[a];
    par[_a] = a;
    return a;
}
void add(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b];
    par[b] = a;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    siz.assign(n, 1);
    par.assign(n, -1);
    vector<int> c(n), deg(n, 0);
    vector<pii> edges;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges.eb(u, v);
        deg[u]++, deg[v]++;
    }
    for (int& e : c) cin >> e;
    for (pii p : edges) {
        if (c[p.fi] != c[p.se]) continue;
        add(p.fi, p.se);
        deg[p.fi]--, deg[p.se]--;
    }
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
        vis[root(i)] = true;
    int k = accumulate(all(vis), 0);
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (deg[i] == k - 1) ans = i + 1;
    if (!ans) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << ans << '\n';
}
