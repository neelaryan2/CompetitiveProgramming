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

vector<int> a, c, path, vis;
vector<vi> cycles;

void dfs(int v) {
    path.pb(v);
    vis[v] = 1;
    int u = a[v];
    if (vis[u] != 2) {
        if (vis[u] == 1) {
            int ptr = path.size() - 1;
            cycles.pb({u});
            while (path[ptr] != u)
                cycles.back().eb(path[ptr--]);
        } else
            dfs(u);
    }
    path.pop_back();
    vis[v] = 2;
}
void solve(int test) {
    int n;
    cin >> n;
    a.resize(n);
    c.resize(n);
    vis.assign(n, 0);
    for (int& e : c)
        cin >> e;
    for (int& e : a)
        cin >> e, e--;
    for (int i = 0; i < n; i++)
        if (!vis[i]) dfs(i);

    int ans = 0;
    for (auto cyc : cycles) {
        int mn = 1e5;
        for (int v : cyc)
            mn = min(mn, c[v]);
        ans += mn;
    }
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
