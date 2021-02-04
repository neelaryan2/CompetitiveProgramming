/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const int N = 2e6 + 10;
const int mxN = 1e5 + 10;
int runmap[N], least[N];
int ans[mxN], a[mxN], depth[mxN];
void sieve() {
    least[0] = 0;
    least[1] = 1;
    for (int i = 2; i < N; i++)
        least[i] = (i & 1) ? i : 2;
    for (int i = 3; i <= N / i; i += 2) {
        if (least[i] != i) continue;
        for (int j = i * i; j < N; j += i)
            if (least[j] == j)
                least[j] = i;
    }
}
vector<vi> adj;
void dfs(int v, int p, int d = 1) {
    vector<pii> prim;
    int num = a[v];
    int& res = ans[v];
    res = -1;
    depth[v] = d;
    while (num > 1) {
        int pr = least[num];
        while (num % pr == 0) num /= pr;
        int& cur = runmap[pr];
        prim.pb({pr, cur});
        if (res == 0 || depth[cur] > depth[res])
            if (cur) res = cur;
        cur = v;
    }
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs(u, v, d + 1);
    }
    for (pii& pr : prim)
        runmap[pr.fi] = pr.se;
}
void update(int v, int w) {
    a[v] = w;
    fill(runmap, runmap + N, 0);
    fill(ans, ans + mxN, 0);
    dfs(1, -1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    update(1, a[1]);
    for (int i = 0; i < q; i++) {
        int t, v, w;
        cin >> t >> v;
        if (t == 2) {
            cin >> w;
            update(v, w);
        } else {
            cout << ans[v] << '\n';
        }
    }
}
