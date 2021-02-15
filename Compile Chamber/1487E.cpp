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

const ll inf = 1e18 + 7;

vector<set<int>> adj;
set<int> unvis;
vector<ll> dp, a;
int num[4];

void dfs(int v, int d) {
    if (d == 3) {
        dp[v] = a[v];
        return;
    }
    vector<int> vec;
    auto itt = unvis.lb(num[d]);
    for (; itt != unvis.end() && *itt < num[d + 1]; itt++) {
        int u = *itt;
        auto it = adj[v].find(u);
        if (it == adj[v].end())
            vec.eb(u);
    }
    if (vec.empty())
        return;
    for (int u : vec)
        unvis.erase(u);
    for (int u : vec) {
        dfs(u, d + 1);
        dp[v] = min(dp[v], a[v] + dp[u]);
    }
}
void solve(int test) {
    int n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;
    int n = n1 + n2 + n3 + n4;
    num[0] = n1;
    num[1] = n1 + n2;
    num[2] = n1 + n2 + n3;
    num[3] = n1 + n2 + n3 + n4;
    adj.assign(n1 + n2 + n3, {});
    a.resize(n);
    dp.assign(n, inf);
    unvis.clear();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        unvis.insert(i);
    }
    int m1, m2, m3;
    cin >> m1;
    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].insert(v + n1);
    }
    cin >> m2;
    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u + n1].insert(v + n1 + n2);
    }
    cin >> m3;
    for (int i = 0; i < m3; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u + n1 + n2].insert(v + n1 + n2 + n3);
    }
    trace(unvis);
    for (int i = 0; i < n1; i++) {
        auto it = unvis.find(i);
        if (it == unvis.end()) continue;
        unvis.erase(it);
        dfs(i, 0);
    }
    ll ans = inf;
    for (int i = 0; i < n1; i++)
        ans = min(ans, dp[i]);
    if (ans >= inf) ans = -1;
    cout << ans;
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
