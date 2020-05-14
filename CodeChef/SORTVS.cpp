#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define shuf(v) shuffle((v).begin(), (v).end(), rng);

vector<int> comp;
vector<vi> mat;
vector<multiset<int>> adj;
int T;
void dfs(int v) {
    comp[v] = T;
    for (int u : mat[v]) {
        if (comp[u] != -1) continue;
        dfs(u);
    }
}
int smallest_cyc(int src) {
    const int inf = 1e9;
    queue<int> q;
    vector<int> dist(T, inf), par(T, -1);
    vector<bool> vis(T, false);
    dist[src] = 0;
    vis[src] = true;
    par[src] = -1;
    q.push(src);
    vector<int> vec;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (u == src) vec.pb(v);
            if (vis[u]) continue;
            dist[u] = dist[v] + 1;
            par[u] = v;
            vis[u] = true;
            q.push(u);
        }
    }
    int mn = -1;
    for (int i : vec)
        if (mn == -1 || dist[i] < dist[mn])
            mn = i;
    vec.clear();
    int v = mn;
    while (v != -1) vec.pb(v), v = par[v];
    adj[mn].erase(adj[mn].find(src));
    for (int i = 1; i < vec.size(); i++) {
        adj[vec[i]].erase(adj[vec[i]].find(vec[i - 1]));
    }
    // for (int i : vec) cerr << i << " ";
    // cerr << endl;
    return vec.size() - 1;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    mat.clear();
    mat.resize(n);
    for (int i = 0; i < n; i++)
        cin >> p[i], p[i]--;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        mat[u].pb(v);
        mat[v].pb(u);
    }
    T = 0;
    comp.assign(n, -1);
    for (int i = 0; i < n; i++) {
        if (comp[i] != -1) continue;
        dfs(i);
        T++;
    }
    adj.clear();
    adj.resize(T);
    vector<bool> vis(n, false);
    ll ans = 1e9;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        int j = i;
        while (!vis[j]) {
            vis[j] = true;
            adj[comp[j]].insert(comp[p[j]]);
            j = p[j];
        }
    }
    for (int i = 0; i < T; i++) {
        while (adj[i].find(i) != adj[i].end())
            adj[i].erase(i);
    }
    vector<multiset<int>> cpy = adj;
    for (int i = 0; i < 5000; i++) {
        ll curr = 0;
        vector<int> vec(T);
        iota(all(vec), 0);
        shuf(vec);
        adj = cpy;
        for (int i : vec) {
            while (!adj[i].empty())
                curr += smallest_cyc(i);
        }
        ans = min(ans, curr);
    }
    // cerr << ans << endl;
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
