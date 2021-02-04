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

vector<vi> adj;
vector<int> cyc, col[2];

void bfs(int s) {
    cyc.clear();
    int n = adj.size();
    queue<int> q;
    vector<bool> vis(n, false);
    vector<int> par(n, -1);
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (par[v] == u) continue;
            if (vis[u]) {
                vector<int> tmp;
                while (u != -1) {
                    tmp.eb(u);
                    u = par[u];
                }
                while (v != -1) {
                    cyc.eb(v);
                    v = par[v];
                }
                int root = -1;
                while (tmp.back() == cyc.back()) {
                    root = tmp.back();
                    tmp.pop_back();
                    cyc.pop_back();
                }
                assert(root != -1);
                cyc.eb(root);
                while (!tmp.empty()) {
                    cyc.eb(tmp.back());
                    tmp.pop_back();
                }
                return;
            } else {
                par[u] = v;
                vis[u] = true;
                q.push(u);
            }
        }
    }
}
void dfs(int v, int p, int c) {
    col[c].eb(v);
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs(u, v, c ^ 1);
    }
}
void solve(int test) {
    int n, m, k;
    cin >> n >> m >> k;
    adj.assign(n, {});

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }

    if (m == n - 1) {
        col[0].clear();
        col[1].clear();
        dfs(0, -1, 0);
        if (col[0].size() < col[1].size())
            swap(col[0], col[1]);
        col[0].resize((k + 1) / 2);
        cout << "1\n";
        for (int v : col[0])
            cout << (v + 1) << ' ';
        return;
    }

    bfs(0);
    if (cyc.size() <= k) {
        cout << "2\n";
        cout << cyc.size() << '\n';
        for (int v : cyc)
            cout << (v + 1) << ' ';
        return;
    }
    trace(cyc);
    cout << "1\n";
    for (int i = 0; i < k; i += 2)
        cout << (cyc[i] + 1) << ' ';
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
