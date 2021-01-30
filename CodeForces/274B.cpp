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
#define rall(v) (v).rbegin(), (v).rend()

const int inf = 1e9 + 7;

vector<ll> a, neg, pos;
vector<vi> adj;

void dfs(int v, int p) {
    neg[v] = 0, pos[v] = 0;
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);
        neg[v] = max(neg[v], neg[u]);
        pos[v] = max(pos[v], pos[u]);
    }
    ll need = a[v] + neg[v] - pos[v];
    if (need > 0)
        pos[v] += need;
    else
        neg[v] -= need;
}
void solve(int test) {
    int n;
    cin >> n;
    adj.resize(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    a.resize(n);
    pos.resize(n);
    neg.resize(n);
    for (ll& e : a) cin >> e;
    dfs(0, -1);
    cout << (neg[0] + pos[0]);
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
        cout << '\n';
    }
}
