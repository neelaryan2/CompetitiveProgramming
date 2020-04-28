#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using ppi = pair<pii, pii>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const int N = 1e5 + 5;
vector<vector<pii>> adj;
vector<ppi> edges;
vector<bool> vis(N);
vector<int> tin(N), low(N), ans(N, 1), siz(N, 1), par(N, -1);
int timer;
void dfs(int v, int p = -1) {
    vis[v] = true;
    tin[v] = low[v] = timer++;
    for (pii t : adj[v]) {
        int to = t.fi;
        int id = t.se;
        if (to == p)
            continue;
        else if (vis[to])
            low[v] = min(low[v], tin[to]);
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                ans[id] = 2;
            }
        }
    }
}
void find_bridges(set<int>& vec) {
    timer = 0;
    for (int i : vec) {
        vis[i] = false;
        tin[i] = -1;
        vis[i] = false;
    }
    for (int i : vec) {
        if (!vis[i])
            dfs(i);
    }
    for (int i : vec) {
        adj[i].clear();
    }
}
int root(int a) {
    if (par[a] == -1) par[a] = a;
    int _a = a;
    while (a != par[a]) a = par[a];
    par[_a] = a;
    return a;
}
void add(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return;
    if (siz[a] == siz[b] && a > b)
        swap(a, b);
    else if (siz[a] < siz[b])
        swap(a, b);
    siz[a] += siz[b];
    par[b] = a;
}
void solve() {
    int n, m;
    cin >> n >> m;
    edges.resize(m);
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges[i] = {{w, i}, {u, v}};
    }
    sort(all(edges));
    int ind = 0;
    while (ind < m) {
        int w = edges[ind].fi.fi;
        set<int> verts;
        map<pii, vi> cnt;
        while (ind < m && edges[ind].fi.fi == w) {
            int u = root(edges[ind].se.fi);
            int v = root(edges[ind].se.se);
            if (u > v) swap(u, v);
            int id = edges[ind].fi.se;
            ind++;
            if (u == v) {
                ans[id] = 0;
            } else {
                auto it = cnt.find({u, v});
                if (it != cnt.end()) {
                    (it->se).eb(id);
                    continue;
                }
                cnt[{u, v}].eb(id);
                adj[u].pb({v, id});
                adj[v].pb({u, id});
                verts.insert(u);
                verts.insert(v);
            }
        }
        find_bridges(verts);
        for (auto pt : cnt) {
            pii p = pt.fi;
            add(p.fi, p.se);
            if (pt.se.size() > 1) {
                for (int idx : pt.se) {
                    ans[idx] = 1;
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int t = ans[i];
        if (t == 0)
            cout << "none\n";
        else if (t == 2)
            cout << "any\n";
        else
            cout << "at least one\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}