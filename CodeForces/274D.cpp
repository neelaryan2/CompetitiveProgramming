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
vector<int> vis, topsort;
vector<vi> adj;
void dfs(int v) {
    vis[v] = 1;
    for (int u : adj[v]) {
        if (vis[u] == 1) {
            cout << "-1\n";
            exit(0);
        }
        if (!vis[u]) dfs(u);
    }
    vis[v] = 2;
    topsort.eb(v);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int ext = m - 1;
    adj.resize(m);
    for (int i = 0; i < n; i++) {
        map<int, vi> cur;
        for (int j = 0; j < m; j++) {
            int e;
            cin >> e;
            if (e != -1) cur[e].eb(j);
        }
        vector<pair<int, vi>> vec(all(cur));
        for (int i = 1; i < vec.size(); i++) {
            adj.eb(), ext++;
            for (int j : vec[i - 1].se) adj[j].eb(ext);
            for (int j : vec[i].se) adj[ext].eb(j);
        }
    }
    vis.assign(ext + 1, false);
    for (int i = 0; i <= ext; i++)
        if (!vis[i]) dfs(i);
    reverse(all(topsort));
    for (int i : topsort)
        if (i < m) cout << i + 1 << ' ';
    cout << '\n';
}
