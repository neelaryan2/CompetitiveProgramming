/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<ll, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const int mod = 1e9 + 7;
map<ll, int> sex;
vector<vi> adj;
vector<ll> x;
int ans = 0;
// map to not create multiple copies, dont try to optimize everything!
void dfs(int v, int pr = -1) {
    map<ll, int> cur, old = sex;
    for (pii p : sex)
        cur[__gcd(p.fi, x[v])] += p.se;
    cur[x[v]]++;
    sex = cur;
    for (pii p : sex)
        ans = (ans + p.fi * p.se) % mod;
    for (int u : adj[v])
        if (u != pr)
            dfs(u, v);
    sex = old;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    adj.resize(n);
    x.resize(n);
    for (ll& e : x) cin >> e;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0);
    cout << ans << '\n';
}
