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
vector<int> tin, tout, dep;
int T = 1;
void dfs(int v, int p = -1, int d = 1) {
    tin[v] = T++;
    dep[v] = d;
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs(u, v, d + 1);
    }
    tout[v] = T;
}
void add(vector<int>& B, int i, int x) {
    int n = B.size();
    for (; i < n; i += i & (-i))
        B[i] = B[i] + x;
}
int sum(vector<int>& B, int i) {
    int sum = 0;
    for (; i > 0; i -= i & (-i))
        sum = sum + B[i];
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    tin.resize(n);
    tout.resize(n);
    dep.resize(n);
    vector<int> a(n);
    for (int& e : a) cin >> e;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    dfs(0);
    vector<int> B(n + 10, 0);
    for (int i = 0; i < m; i++) {
        int t, x;
        cin >> t >> x;
        x--;
        if (t == 1) {
            int val;
            cin >> val;
            if (dep[x] & 1) val *= -1;
            add(B, tin[x], val);
            add(B, tout[x], -val);

        } else if (t == 2) {
            int ans = sum(B, tin[x]);
            if (dep[x] & 1) ans *= -1;
            cout << ans + a[x] << '\n';
        }
    }
}
