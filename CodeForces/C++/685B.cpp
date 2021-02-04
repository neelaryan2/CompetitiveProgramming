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
vector<vi> adj;
vector<int> siz, ans, mx;
set<pii> s;
void dfs0(int v) {
    for (int u : adj[v]) {
        dfs0(u);
        siz[v] += siz[u];
        mx[v] = max(mx[v], siz[u]);
    }
}
void dfs(int v) {
    s.insert(mp(siz[v], v));
    for (int u : adj[v]) dfs(u);
    auto it1 = s.lb(mp(2 * mx[v], -1));
    auto it2 = s.lb(mp(2 * siz[v], -1));
    for (auto it = it1; it != it2;) {
        ans[it->se] = v + 1;
        it = s.erase(it);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    adj.resize(n);
    ans.assign(n, -1);
    siz.assign(n, 1);
    mx.assign(n, 0);
    for (int i = 1, p; i < n; i++) {
        cin >> p, p--;
        adj[p].pb(i);
    }
    trace(adj);
    dfs0(0);
    dfs(0);
    assert(s.empty());
    for (int i = 0, v; i < q; i++) {
        cin >> v, v--;
        cout << ans[v] << '\n';
    }
}
