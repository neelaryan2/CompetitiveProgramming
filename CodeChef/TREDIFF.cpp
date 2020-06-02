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
using vi = vector<int>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
int n, LOGN, q;
vector<vector<pii>> adj;
vector<vector<int>> P;
vector<ll> depth, arr;
int lca(int p, int q) {
    if (depth[p] < depth[q]) swap(p, q);
    for (int i = LOGN - 1; i >= 0; i--)
        if (depth[p] - depth[q] >= (1 << i))
            p = P[p][i];
    if (p == q) return p;
    for (int i = LOGN - 1; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];
    return P[p][0];
}
void dfs(int v, int pr = -1) {
    P[v][0] = pr;
    for (int j = 1; j < LOGN; j++)
        if (P[v][j - 1] != -1)
            P[v][j] = P[P[v][j - 1]][j - 1];
    for (auto t : adj[v]) {
        int u = t.fi;
        if (u == pr) continue;
        depth[u] = depth[v] + 1;
        dfs(u, v);
    }
}
void init() {
    cin >> n >> q;
    LOGN = 0;
    for (; (1 << LOGN) < n; LOGN++) {
    }
    arr.resize(n);
    depth.resize(n);
    adj.clear();
    adj.resize(n);
    P.clear();
    P.assign(n, vector<int>(LOGN));
}
void solve() {
    init();
    for (ll& e : arr) cin >> e;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].eb(v, i);
        adj[v].eb(u, i);
    }
    depth[0] = 0;
    dfs(0);
    for (int i = 0; i < q; i++) {
        int a, b, l, h1, h2;
        cin >> a >> b;
        a--, b--;
        l = lca(a, b);
        h1 = depth[a] - depth[l];
        h2 = depth[b] - depth[l];
        if (h1 + h2 >= 205) {
            cout << "0\n";
            continue;
        }
        ll ans = 1e18;
        vector<ll> vec;
        while (a != l) vec.pb(arr[a]), a = P[a][0];
        while (b != l) vec.pb(arr[b]), b = P[b][0];
        vec.pb(arr[l]);
        sort(all(vec));
        trace(vec);
        for (int j = 1; j < vec.size(); j++) {
            ans = min(ans, abs(vec[j] - vec[j - 1]));
        }
        cout << ans << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
