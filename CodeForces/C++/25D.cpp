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
int T = 0;
vector<vi> adj;
set<pii> ext;
vector<int> comp;
void dfs(int v) {
    comp[v] = T;
    for (int u : adj[v]) {
        if (comp[u] == T) continue;
        pii p = mp(u, v);
        if (p.fi > p.se) swap(p.fi, p.se);
        ext.erase(p);
        dfs(u);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    adj.resize(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
        pii p = mp(u, v);
        if (p.fi > p.se) swap(p.fi, p.se);
        ext.insert(p);
    }
    comp.assign(n, -1);
    vector<int> rep;
    for (int i = 0; i < n; i++) {
        if (comp[i] != -1) continue;
        dfs(i);
        rep.pb(i);
        T++;
    }
    cout << T - 1 << '\n';
    for (int i = 1; i < T; i++) {
        pii p = *ext.begin();
        ext.erase(p);
        cout << p.fi + 1 << ' ' << p.se + 1;
        cout << ' ' << rep[i] + 1 << ' ' << rep[i - 1] + 1;
        cout << '\n';
    }
}
